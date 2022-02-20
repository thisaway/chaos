//VectorExprOperator.h
#ifndef CHAOS_ARITHMETIC_EXPR_VECTOREXPROPERATOR_H
#define CHAOS_ARITHMETIC_EXPR_VECTOREXPROPERATOR_H

#include "VectorExprFun.h"

namespace chaos {

template<typename E1, typename E2, size_t Size>
inline
VectorExpr<  \
  BinaryExpr<  \
    AddFun<typename E1::valueType, typename E2::valueType>,  \
    VectorExpr<E1, Size>,  \
    VectorExpr<E2, Size>  \
  >,  \
  Size  \
>
operator+(const VectorExpr<E1, Size>& vexpr1, const VectorExpr<E1, Size>& vexpr2) {
    
    return add(vexpr1, vexpr2);
}

}  //namespace

#endif
