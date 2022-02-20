//TensorExpr.h
#ifndef CHAOS_ARITHMTIC_EXPR_TENSOREXPR_H
#define CHAOS_ARITHMTIC_EXPR_TENSOREXPR_H

#include "ArithmticBase.h"
#include "Core.h"

namespace chaos {

template<typename _Expr, size_t _Rows, size_t _Cols, size_t _Ranks>
class TensorExpr : public ArithmticBase< TensorExpr<_Expr, _Rows, _Cols, _Ranks> > {

private:
  TensorExpr();
  TensorExpr& operator=(const TensorExpr&);

public:
  enum { 
    Rows = _Rows,
    Cols = _Cols,
    Ranks = _Ranks,
    Size = Rows * Cols * Ranks
  };

  typedef typename _Expr::valueType    valueType;

public:
  explicit TensorExpr(const _Expr& e)
    : expr(e) { }
  
  valueType operator()(size_t i, size_t j, size_t k) const {
    ASSERT_CHAO(i < Rows and j < Cols and k < Ranks);
    return e(i, j, k);
  }

private:
  const _Expr    expr;
};
}  //namespace

#endif