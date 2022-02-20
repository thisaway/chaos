//LiteralExpr.h
#ifndef CHAOS_ARITHMETIC_EXPR_LITERALEXPR_H
#define CHAOS_ARITHMETIC_EXPR_LITERALEXPR_H

namespace chaos {

template<typename _Literal>
class LiteralExpr : ArithmeticBase< LiteralExpr<_Literal> > {

private:
  LiteralExpr();
  LiteralExpr& operator=(const LiteralExpr&);

public:
  typedef typename _Literal    valueType;

  explicit LiteralExpr(const _Literal& c)
    : constant(c) { }

  //for Vector;
  INLINE_CHAOS _Literal operator()(size_t i) const {
    return constant;
  }
  
  //for Matrix;
  INLINE_CHAOS _Literal operator()(size_t i, size_t j) const {
    return constant;
  }

  //for Tensor;
  INLINE_CHAOS _Literal operator()(size_t i, size_t j, size_t k) const {
    return constant;
  }

private:
  const _Literal    constant;
};

}  //namespace

#endif