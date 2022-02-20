//BinaryFun.h
#ifndef CHAOS_ARITHMETIC_BINARYFUN_H
#define CHAOS_ARITHMETIC_BINARYFUN_H

#include "TypePromotion.h"

namespace chaos {

template<typename T1, typename T2>
class AssignFun {

public:
  static inline
  void applyOn(T1& lhs, T2 rhs) {
      lhs = static_cast<T1>(rhs);
  }
};

template<typename T1, typename T2>
class AddFun {

public:
  typedef typename  PromoteTraits<T1, T2>::valueType    valueType;

  static inline valueType calculate(T1 lhs, T2 rhs) {
      return lhs + rhs;
  }
};

}  //namespace

#endif