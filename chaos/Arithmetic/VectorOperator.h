//VectorOperator.h
#ifndef CHAOS_ARITHMETIC_VECTOROPERATOR_H
#define CHAOS_ARITHMETIC_VECTOROPERATOR_H

#include "VectorFun.h"

#include <iostream>  //test

namespace chaos {

template<typename T1, typename T2, size_t Size>
inline
VectorExpr<  \
  BinaryExpr<  \
    VectorConstReference<T1, Size>,  \
    VectorConstReference<T2, Size>,  \
    AddFun<T1, T2>  \
  >,  \
  Size  \
>
operator+(const Vector<T1, Size>& lhs, const Vector<T2, Size>& rhs) {

    //test
    //std::cout << "operator+ lhs(0):" << lhs(0) << " " << "rhs(0):" <<rhs(0) << std::endl;

    return add(lhs, rhs);
}

}  //namespace

#endif