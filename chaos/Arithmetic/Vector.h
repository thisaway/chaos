//Vector.h
#ifndef CHAOS_ARITHMETIC_VECTOR_H
#define CHAOS_ARITHMETIC_VECTOR_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"
#include "BinaryFun.h"
#include "VectorExpr.h"

#include <iostream> //test


namespace chaos {

template<typename T, size_t Size> class Vector;

template<typename T, size_t Size>
class VectorConstReference : public ArithmeticBase< VectorConstReference<T, Size> > {
public:
  typedef T    valueType;
  typedef T*    pointer;
  typedef const T*    constPointer;

public:
  enum {
    size = Size
  };

private:
  VectorConstReference();
  VectorConstReference& operator=(const VectorConstReference&);

public:
  ~VectorConstReference() { }

  //explicit VectorConstReference(const VectorConstReference& vcr)
  //  : inData(vcr.inData) { }
  
  explicit VectorConstReference(const Vector<T, size>& v)
    : inData(v.data()) { }
  
  explicit VectorConstReference(constPointer ptr)
    : inData(ptr) { }
  
  valueType operator()(size_t i) const {
      ASSERT_CHAOS(i < size);
      return *(inData + i);
  }

private:
  constPointer inData;
};

template<typename T, size_t Length>
class Vector : public ArithmeticBase< Vector<T, Length> > {
public:
  typedef T    valueType;

//private:
  enum {
      size = Length
  };

public:
  ~Vector() { }
  Vector() {
      std::cout << "Vector construct no param" << std::endl;
  }
  
  Vector(const Vector& v) {
      std::cout << "Vector copy construct" << std::endl;
      *this = VectorExpr<ConstReference, size>(v.constRef());
  }

  template<typename E>
  explicit Vector(const VectorExpr<E, size>& e) {
      std::cout << "Vector construct from VectorExpr" << std::endl;
      *this = e;
  }

public:
  template<typename TT>
  Vector& operator=(const Vector<TT, size>& v) {
      v.assignTo(*this, AssignFun<valueType, TT>());

      return *this;
  }

  template<typename E>
  Vector& operator=(const VectorExpr<E, size>& ve) {

      std::cout << "Vector operator=" << std::endl;
      
      //test
      //std::cout << ve.operator()(0) << std::endl;
      //std::cout << "Test VectorExpr 0:" << ve(0) << std::endl;
      ve.assignTo(*this, AssignFun<valueType, typename E::valueType>());

      return *this;
  }

  //Init
  Vector& operator<<(valueType value) {
      ASSERT_CHAOS(0 < size);
      inData[0] = value;
      initIndex = 1;
      return *this;
  }

  Vector& operator,(valueType value) {
      ASSERT_CHAOS(initIndex < size);
      inData[initIndex++] = value;
      return *this;
  }

public:
  typedef VectorConstReference<T, size> ConstReference;
  ConstReference constRef() const { return ConstReference(*this); }

public:
  valueType* data() { return inData; }

  const valueType* data() const { return inData; }

  valueType operator()(size_t i) const { 

      ASSERT_CHAOS(i < size);
      return inData[i];
  }

  valueType& operator()(size_t i) {

      ASSERT_CHAOS(i < size);
      return inData[i];
  }

  template<typename Dest, typename Assign>
  void assignTo(Dest& d, const Assign& assignFun) {
      doAssign(d, *this, assignFun);
  }

private:
  template<typename Dest, typename Src, typename Assign>
  static inline void doAssign(Dest& d, const Src& s, const Assign& assignFun) {
      for(size_t i = 0; i < size; ++i) {
          //test
          //std::cout << "vector do assign:" << s(i) << std::endl;
          assignFun.applyOn(d(i), s(i));
      }
  }

private:
  valueType inData[size];
  size_t initIndex = 0;
};

}  //namespace chaos;

#include "VectorFun.h"
#include "VectorOperator.h"

#endif