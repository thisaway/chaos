//MatrixFun.h
#ifndef CHAOS_ARITHMETIC_MATRIXFUN_H
#define CHAOS_ARITHMETIC_MATRIXFUN_H

#include "Matrix.h"
#include "BinaryExpr.h"

namespace chaos {

#define MATRIX_BINARY_FUN(bin)  \
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
bin(const Matrix<T1, Rows, Cols>& lhs, const Matrix<T2, Rows, Cols>& rhs) {  \
  \
    typedef BinaryExpr<  \
              MatrixConstReference<T1, Rows, Cols>,  \
              MatrixConstReference<T2, Rows, Cols>,  \
              bin##Fun<T1, T2>  \
            >  expr;  \
  \
    return MatrixExpr<expr, Rows, Cols>(expr(lhs.constRef(), rhs.constRef()));  \
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
bin(const Matrix<T, Rows, Cols>& lhs, const MatrixExpr<E, Rows, Cols>& rhs) {  \
  \
    typedef BinaryExpr<  \
              MatrixConstReference<T, Rows, Cols>,  \
              MatrixExpr<E, Rows, Cols>,  \
              bin##Fun<T, typename E::valueType>  \
            >  expr;  \
  \
    return MatrixExpr<expr, Rows, Cols>(expr(lhs.constRef(), rhs));  \
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
bin(const MatrixExpr<E, Rows, Cols>& lhs, const Matrix<T, Rows, Cols>& rhs) {  \
  \
    typedef BinaryExpr<  \
              MatrixExpr<E, Rows, Cols>,  \
              MatrixConstReference<T, Rows, Cols>,  \
              bin##Fun<typename E::valueType, T>  \
            >  expr;  \
  \
    return MatrixExpr<expr, Rows, Cols>(expr(lhs, rhs.constRef()));  \
}

MATRIX_BINARY_FUN(Add)
MATRIX_BINARY_FUN(Sub)
MATRIX_BINARY_FUN(Mul)
MATRIX_BINARY_FUN(Div)

#undef MATRIX_BINARY_FUN

}  //namespace

#endif