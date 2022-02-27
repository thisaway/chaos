//VectorExpr.h
#ifndef CHAOS_ARITHMETIC_EXPR_VECTOREXPR_H
#define CHAOS_ARITHMETIC_EXPR_VECTOREXPR_H

#include "Arithmetic.h"
#include "ArithmeticBase.h"

namespace chaos {

template<typename Expr, size_t Length>
class VectorExpr : public ArithmeticBase< VectorExpr<Expr, Length> > {

private:
  VectorExpr();
  VectorExpr& operator=(const VectorExpr&);

public:
  enum { 
    size = Length
  };

  typedef typename Expr::valueType    valueType;

public:
  VectorExpr(const VectorExpr& ve)
    : expr(ve.expr) { }

  explicit VectorExpr(const Expr& e)
    : expr(e) { }
  
  //for Vector;
  valueType operator()(size_t i) const {

    ASSERT_CHAOS(i < size);
    return expr(i);
  }

  template<typename Dest, typename Assign>
  void assignTo(Dest& d, const Assign& assignFun) const {
      
      ASSERT_CHAOS(d.size == this->size);
      doAssign(d, *this, assignFun);
  }

private:
  template<typename Dest, typename Src, typename Assign>
  static inline void doAssign(Dest& d, const Src& s, const Assign& assignFun) {

      for(size_t i = 0; i < size; ++i) {

          assignFun.applyOn(d(i), s(i));
      }
  }

private:
  const Expr    expr;
};

}  //namespace

#include "VectorExprFun.h"
#include "VectorExprOperator.h"

#endif