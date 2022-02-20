//UnaryExpr.h
#ifndef CHAOS_ARITHMTIC_EXPR_UNARYOPEXPR_H
#define CHAOS_ARITHMTIC_EXPR_UNARYOPEXPR_H

namespace chaos {

template<typename _Expr, typename _Op>
class UnaryOpExpr : public ArithmticBase< UnaryOpExpr<_Expr, _Op> > {

private:
  UnaryOpExpr();
  UnaryOpExpr& operator=(const UnaryOpExpr&);

public:
  typedef _Expr    exprType;
  typedef _Op      opType;

  typedef typename exprType::valueType    valueType;

  explicit UnaryOpExpr(exprType e, opType o)
    : expr(e), op(o) { }

private:
  const valueType    expr;
};

}