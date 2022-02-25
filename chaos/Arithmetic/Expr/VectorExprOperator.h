//VectorExprOperator.h
#ifndef CHAOS_ARITHMETIC_EXPR_VECTOREXPROPERATOR_H
#define CHAOS_ARITHMETIC_EXPR_VECTOREXPROPERATOR_H

#include "VectorExprFun.h"

namespace chaos {

#define VECTOREXPR_BINARY(bin, op)  \
  \
template<typename E1, typename E2, size_t Size>  \
inline  \
VectorExpr<  \
  BinaryExpr<  \
    VectorExpr<E1, Size>,  \
    VectorExpr<E2, Size>,  \
    bin##Fun<typename E1::valueType, typename E2::valueType>  \
  >,  \
  Size  \
>  \
operator op (const VectorExpr<E1, Size>& vexpr1, const VectorExpr<E2, Size>& vexpr2) {  \
  \
    return bin(vexpr1, vexpr2);  \
}

VECTOREXPR_BINARY(Add, +)
VECTOREXPR_BINARY(Sub, -)
VECTOREXPR_BINARY(Mul, *)
VECTOREXPR_BINARY(Div, /)

#undef VECTOREXPR_BINARY

}  //namespace

#endif
