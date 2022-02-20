//Variable.h
#ifndef CHAOS_ARITHMTIC_EXPR_VARIABLEEXPR_H
#define CHAOS_ARITHMTIC_EXPR_VARIABLEEXPR_H

namespace chaos {

template<typename _Variable>
class VariableExpr : public ArithmticBase<VariableExpr> {

private:
  VariableExpr();
  VariableExpr& operator=(const VariableExpr&);

public:
  typedef typename _Variable    valueType;
  
  explicit VariableExpr(const valueType& v)
    : var(v) { }
  
  valueType operator()() const {

    return var;
  }

private:
  const valueType    var;
};

}  //namespace

#endif
