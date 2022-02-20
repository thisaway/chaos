//BinaryExpr.h
#ifndef CHAOS_ARITHMETIC_EXPR_BINARYEXPR_H
#define CHAOS_ARITHMETIC_EXPR_BINARYEXPR_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"

#include <iostream>

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
    : expr1(v1), expr2(v2) { 
      
      //test
      std::cout << "binaryExpr construct:" << "v1(0):" << v1(0) << " " << "v2(0):" << v2(0) << std::endl;
      std::cout << "BinOp:" << Op::calculate(v1(4), v2(4)) << std::endl;
  }

  valueType operator()(size_t i) const{

    //std::cout << "BinOp:" << Op::calculate(expr1(i), expr2(i)) << std::endl;
    //std::cout << "expr1:" << expr1(i) << std::endl;
    //std::cout << "expr2:" << expr2(i) << std::endl;
    return Op::calculate(expr1(i), expr2(i));
  }
  
private:
  const Expr1    expr1;
  const Expr2    expr2;
};

}  //namespace

#endif