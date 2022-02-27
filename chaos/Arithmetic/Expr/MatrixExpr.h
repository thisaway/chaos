//MatrixExpr.h
#ifndef CHAOS_ARITHMETIC_EXPR_MATRIXEXPR_H
#define CHAOS_ARITHMETIC_EXPR_MATRIXEXPR_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"
#include "BinaryExpr.h"

namespace chaos {

template<typename E, size_t Rows, size_t Cols>
class MatrixExpr : public ArithmeticBase< MatrixExpr<E, Rows, Cols> > {

private:
  MatrixExpr();
  MatrixExpr& operator=(const MatrixExpr&);

public:
  enum {
    rows = Rows,
    cols = Cols,
    size = Rows * Cols
  };
  
  typedef typename E::valueType    valueType;

public:
  explicit MatrixExpr(const E& e)
    : expr(e) { }

  valueType operator()(size_t r, size_t c) const {

      ASSERT_CHAOS(r < rows and c < cols);
      return expr(r, c);
  }

  template<typename Dest, typename Assign>
  void assignTo(Dest& d, const Assign& assignFun) const {

      ASSERT_CHAOS(d.cols == cols and d.rows == rows);
      doAssign(d, *this, assignFun);
  }

private:
  template<typename Dest, typename Src, typename Assign>
  static void doAssign(Dest& d, const Src& s, const Assign& assignFun) {

      for(size_t r = 0; r < s.rows; ++r) {
          for(size_t c = 0; c < s.cols; ++c) {

              assignFun.applyOn(d(r, c), s(r, c));
          }
      }
  }

private:
  const E expr;

};

}  //namespace

#include "MatrixExprFun.h"
#include "MatrixExprOperator.h"

#endif