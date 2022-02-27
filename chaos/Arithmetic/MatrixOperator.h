//MatrixOperator.h
#ifndef CHAOS_ARITHMETIC_MATRIXOPERATOR_H
#define CHAOS_ARITHMETIC_MATRIXOPERATOR_H

#include "MatrixFun.h"

namespace chaos {

#define MATRIX_BINARY(bin, op)  \
  \
template<typename T1, typename T2, size_t Rows, size_t Cols>  \
inline  \
MatrixExpr<  \
  BinaryExpr<  \
    MatrixConstReference<T1, Rows, Cols>,  \
    MatrixConstReference<T2, Rows, Cols>,  \
    bin##Fun<T1, T2>  \
  >,  \
  Rows,  \
  Cols  \
>  \
operator op (const Matrix<T1, Rows, Cols>& lhs, const Matrix<T2, Rows, Cols>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}  \
  \
template<typename T, typename E, size_t Rows, size_t Cols>  \
inline  \
MatrixExpr<  \
  BinaryExpr<  \
    MatrixConstReference<T, Rows, Cols>,  \
    MatrixExpr<E, Rows, Cols>,  \
    bin##Fun<T, typename E::valueType>  \
  >,  \
  Rows,  \
  Cols  \
>  \
operator op (const Matrix<T, Rows, Cols>& lhs, const MatrixExpr<E, Rows, Cols>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}  \
  \
template<typename E, typename T, size_t Rows, size_t Cols>  \
inline  \
MatrixExpr<  \
  BinaryExpr<  \
    MatrixExpr<E, Rows, Cols>,  \
    MatrixConstReference<T, Rows, Cols>,  \
    bin##Fun<typename E::valueType, T>  \
  >,  \
  Rows,  \
  Cols  \
>  \
operator op (const MatrixExpr<E, Rows, Cols>& lhs, const Matrix<T, Rows, Cols>& rhs) {  \
  \
    return bin(lhs, rhs);  \
}

MATRIX_BINARY(Add, +)
MATRIX_BINARY(Sub, -)
MATRIX_BINARY(Mul, *)
MATRIX_BINARY(Div, /)

#undef MATRIX_BINARY_FUN

}  //namespace

#endif