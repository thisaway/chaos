//VectorFun.h
#ifndef CHAOS_ARITHMETIC_VECTORFUN_H
#define CHAOS_ARITHMETIC_VECTORFUN_H

#include "VectorExpr.h"
#include "BinaryExpr.h"
#include "Vector.h"

#include <iostream>  //test

namespace chaos {

#define VECTOR_BINARY_FUN(bin)  \
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
bin(const Vector<T1, Size>& lhs, const Vector<T2, Size>& rhs) {  \
  \
    typedef BinaryExpr<  \
              VectorConstReference<T1, Size>,  \
              VectorConstReference<T2, Size>,  \
              bin##Fun<T1, T2>  \
            >  \
            expr;  \
  \
    return VectorExpr<expr, Size>(expr(lhs.constRef(), rhs.constRef()));  \
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
bin(const VectorExpr<E, Size>& lhs, const Vector<T, Size>& rhs) {  \
  \
    typedef BinaryExpr<  \
              VectorExpr<E, Size>,  \
              VectorConstReference<T, Size>,  \
              bin##Fun<typename E::valueType, T>  \
            >  \
            expr;  \
  \
    return VectorExpr<expr, Size>(expr(lhs, rhs.constRef()));  \
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
bin(const Vector<T, Size>& lhs, const VectorExpr<E, Size>& rhs) {  \
  \
    typedef BinaryExpr<  \
              VectorConstReference<T, Size>,  \
              VectorExpr<E, Size>,  \
              bin##Fun<T, typename E::valueType>  \
            >  \
            expr;  \
  \
    return VectorExpr<expr, Size>(expr(lhs.constRef(), rhs));  \
}

VECTOR_BINARY_FUN(Add)
VECTOR_BINARY_FUN(Sub)
VECTOR_BINARY_FUN(Mul)
VECTOR_BINARY_FUN(Div)

#undef VECTOR_BINARY_FUN


}  //namespace

#endif