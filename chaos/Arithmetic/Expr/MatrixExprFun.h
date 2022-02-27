//MatrixExprFun.h
#ifndef CHAOS_ARITHMETIC_EXPR_MATRIXEXPRFUN_H
#define CHAOS_ARITHMETIC_EXPR_MATRIXEXPRFUN_H

#include "MatrixExpr.h"
#include "BinaryFun.h"

namespace chaos {

#define MATRIXEXPR_BINARY_FUN(bin)  \
  \
template<typename E1, typename E2, size_t Rows, size_t Cols>  \
inline  \
MatrixExpr<  \
  BinaryExpr<  \
    MatrixExpr<E1, Rows, Cols>,  \
    MatrixExpr<E2, Rows, Cols>,  \
    bin##Fun<typename E1::valueType, typename E2::valueType>  \
  >,  \
  Rows,  \
  Cols  \
>  \
bin(const MatrixExpr<E1, Rows, Cols>& lhs, const MatrixExpr<E2, Rows, Cols>& rhs) {  \
  \
    typedef BinaryExpr<  \
              MatrixExpr<E1, Rows, Cols>,  \
              MatrixExpr<E2, Rows, Cols>,  \
              bin##Fun<typename E1::valueType, typename E2::valueType>  \
            >  expr;  \
  \
    return MatrixExpr<expr, Rows, Cols>(expr(lhs, rhs));  \
}

MATRIXEXPR_BINARY_FUN(Add)
MATRIXEXPR_BINARY_FUN(Sub)
MATRIXEXPR_BINARY_FUN(Mul)
MATRIXEXPR_BINARY_FUN(Div)

#undef MATRIXEXPR_BINARY_FUN

}  //namespace

#endif