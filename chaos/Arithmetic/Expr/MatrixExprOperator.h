//MatrixExprOperator.h
#ifndef CHAOS_ARITHMETIC_EXPR_MATRIXEXPROPERATOR_H
#define CHAOS_ARITHMETIC_EXPR_MATRIXEXPROPERATOR_H

#include "MatrixExprFun.h"

namespace chaos {

#define MATRIXEXPR_BINARY(bin, op)  \
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
operator op (const MatrixExpr<E1, Rows, Cols>& mexpr1, const MatrixExpr<E2, Rows, Cols>& mexpr2) {  \
  \
    return bin(mexpr1, mexpr2);  \
}

MATRIXEXPR_BINARY(Add, +)
MATRIXEXPR_BINARY(Sub, -)
MATRIXEXPR_BINARY(Mul, *)
MATRIXEXPR_BINARY(Div, /)

#undef MATRIXEXPR_BINARY

}//namespace

#endif