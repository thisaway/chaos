//BinaryExpr.h
#ifndef CHAOS_ARITHMETIC_EXPR_BINARYEXPR_H
#define CHAOS_ARITHMETIC_EXPR_BINARYEXPR_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"

namespace chaos {

template<typename Expr1, typename Expr2, typename Op>
class BinaryExpr : public ArithmeticBase< BinaryExpr<Expr1, Expr2, Op> >{

private:
  BinaryExpr();
  BinaryExpr& operator=(const BinaryExpr&);

public:
  typedef typename Op::valueType    valueType;

  BinaryExpr(const BinaryExpr& binExpr)
    : expr1(binExpr.expr1), expr2(binExpr.expr2) { }

  explicit BinaryExpr(const Expr1& v1, const Expr2& v2)
    : expr1(v1), expr2(v2) { }

  //For Vector;
  valueType operator()(size_t i) const{

      return Op::calculate(expr1(i), expr2(i));
  }

  //For Matrix;
  valueType operator()(size_t r, size_t c) const {

      return Op::calculate(expr1(r, c), expr2(r, c));
  }
  
private:
  const Expr1    expr1;
  const Expr2    expr2;
};

}  //namespace

#endif