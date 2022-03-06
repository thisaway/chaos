//Matrix.h
#ifndef CHAOS_ARITHMETIC_MATRIX_H
#define CHAOS_ARITHMETIC_MATRIX_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"
#include "MatrixExpr.h"

namespace chaos {

template<typename T, size_t Rows, size_t Cols> class Matrix;

template<typename T, size_t Rows, size_t Cols>
class MatrixConstReference : public ArithmeticBase< MatrixConstReference<T, Rows, Cols> > {

public:
  typedef T    valueType;
  typedef T*    pointer;
  typedef const T*    constPointer;

  enum {
    rows = Rows,
    cols = Cols,
    size = Rows * Cols
  };

private:
  MatrixConstReference();
  MatrixConstReference& operator=(const MatrixConstReference&);

public:
  ~MatrixConstReference() { }

  explicit MatrixConstReference(const Matrix<T, Rows, Cols>& m)
    : inData(m.data()) { }

  valueType operator()(size_t r, size_t c) const {

      ASSERT_CHAOS(r < rows and c < cols);
      return inData[r * cols + c];
  }

private:
  constPointer inData;
};

template<typename T, size_t Rows, size_t Cols>
class Matrix : public ArithmeticBase< Matrix<T, Rows, Cols> > {

public:
  typedef T    valueType;

  enum {
    rows = Rows,
    cols = Cols,
    size = Rows * Cols,
    use_heap_memory = size <= TRIGGER_HEAP_MEMORY_ALLOC
  };

public:
  ~Matrix() { }

  Matrix()
  #if(use_heap_memory)
  : inData(new valueType[size])
  #endif
  { }

  Matrix(const Matrix& m) 
  #if(use_heap_memory)
  : inData(new valueType[size])
  #endif
  {

      *this = MatrixExpr<ConstReference, rows, cols>(m.constRef());
  }
  
  template<typename E>
  explicit Matrix(const MatrixExpr<E, Rows, Cols>& mexpr)
  #if(use_heap_memory)
  : inData(new valueType[size])
  #endif
  {

      *this = mexpr;
  }

  template<typename TT>
  Matrix& operator=(const Matrix<TT, Rows, Cols>& m) 
  #if(use_heap_memory)
  : inData(new valueType[size])
  #endif
  {

      m.assignTo(*this, AssignFun<valueType, TT>());
      return *this;
  }

  template<typename E>
  Matrix& operator=(const MatrixExpr<E, Rows, Cols>& mexpr) 
  #if(use_heap_memory)
  : inData(new valueType[size])
  #endif
  {

      mexpr.assignTo(*this, AssignFun<valueType, typename E::valueType>());
      return *this;
  }

  //Init
  Matrix& operator<<(valueType value) {

      ASSERT_CHAOS(0 < size);
      inData[0] = value;
      initIndex = 1;
      return *this;
  }

  Matrix& operator,(valueType value) {

      ASSERT_CHAOS(initIndex < size);
      inData[initIndex++] = value;
      return *this;
  }

public:
  typedef MatrixConstReference<T, Rows, Cols>    ConstReference;
  ConstReference constRef() const {

      return ConstReference(*this);
  }

public:
  valueType* data() {return inData;}

  const valueType* data() const {return inData;}

  valueType operator()(size_t r, size_t c) const {

      ASSERT_CHAOS(r < rows and c < cols);
      return inData[r * cols + c];
  }

  valueType& operator()(size_t r, size_t c) {

      ASSERT_CHAOS(r < rows and c < cols);
      return inData[r * cols + c];
  }

template<typename Dest, typename Assign>
  void assignTo(Dest& d, const Assign& assignFun) const {

      ASSERT_CHAOS(d.cols == cols and d.rows == rows);
      doAssign(d, *this, assignFun);
  }

private:
  template<typename Dest, typename Src, typename Assign>
  static void doAssign(Dest& d, const Src& s, const Assign& assignFun) {

      for(size_t r = 0; r < s.rows; ++r) {
          for(size_t c = 0; c < s.cols; ++c) {

              assignFun.applyOn(d(r, c), s(r, c));
          }
      }
  }

private:
#if(use_heap_memory)
  valueType* inData;
#else
  valueType inData[size];
#endif
  size_t initIndex;
};

}  //namespace

#include "MatrixFun.h"
#include "MatrixOperator.h"

#endif