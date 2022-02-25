//VectorOperator.h
#ifndef CHAOS_ARITHMETIC_VECTOROPERATOR_H
#define CHAOS_ARITHMETIC_VECTOROPERATOR_H

#include "VectorFun.h"

#include <iostream>  //test

namespace chaos {

#define VECTOR_BINARY(bin, op)  \
  \
template<typename T1, typename T2, size_t Size>  \
inline  \
VectorExpr<  \
  BinaryExpr<  \
    VectorConstReference<T1, Size>,  \
    VectorConstReference<T2, Size>,  \
    bin##Fun<T1, T2>  \
  >,  \
  Size  \
>  \
operator op (const Vector<T1, Size>& lhs, const Vector<T2, Size>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}  \
  \
template<typename E, typename T, size_t Size>  \
inline  \
VectorExpr<  \
  BinaryExpr<  \
    VectorExpr<E, Size>,  \
    VectorConstReference<T, Size>,  \
    bin##Fun<typename E::valueType, T>  \
  >,  \
  Size  \
>  \
operator op (const VectorExpr<E, Size>& lhs, const Vector<T, Size>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}  \
  \
template<typename T, typename E, size_t Size>  \
inline  \
VectorExpr<  \
  BinaryExpr<  \
    VectorConstReference<T, Size>,  \
    VectorExpr<E, Size>,  \
    bin##Fun<T, typename E::valueType>  \
  >,  \
  Size  \
>  \
operator op (const Vector<T, Size>& lhs, const VectorExpr<E, Size>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}

VECTOR_BINARY(Add, +)
VECTOR_BINARY(Sub, -)
VECTOR_BINARY(Mul, *)
VECTOR_BINARY(Div, /)

#undef VECTOR_BINARY

}  //namespace

#endif