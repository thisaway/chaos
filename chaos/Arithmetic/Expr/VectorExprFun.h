//VectorExprFun.h
#ifndef CHAOS_ARITHMETIC_EXPR_VECTOREXPRFUN_H
#define CHAOS_ARITHMETIC_EXPR_VECTOREXPRFUN_H

#include "VectorExpr.h"
#include "BinaryExpr.h"
#include "BinaryFun.h"

namespace chaos {

#define VECTOREXPR_BINARY_FUN(bin)  \
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
bin(const VectorExpr<E1, Size>& vexpr1, const VectorExpr<E2, Size>& vexpr2) {  \
  \
    typedef BinaryExpr<  \
              VectorExpr<E1, Size>,  \
              VectorExpr<E2, Size>,  \
              bin##Fun<typename E1::valueType, typename E2::valueType>  \
            >  expr;  \
  \
    return VectorExpr<expr, Size>(expr(vexpr1, vexpr2));  \
}

VECTOREXPR_BINARY_FUN(Add)
VECTOREXPR_BINARY_FUN(Sub)
VECTOREXPR_BINARY_FUN(Mul)
VECTOREXPR_BINARY_FUN(Div)

#undef VECTOREXPR_BINARY_FUN

}  //namespace

#endif