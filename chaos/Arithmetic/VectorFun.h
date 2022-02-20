//VectorFun.h
#ifndef CHAOS_ARITHMETIC_VECTORFUN_H
#define CHAOS_ARITHMETIC_VECTORFUN_H

#include "VectorExpr.h"
#include "BinaryExpr.h"
#include "Vector.h"

#include <iostream>  //test

namespace chaos {

template<typename T1, typename T2, size_t Size>
inline
VectorExpr<  \
  BinaryExpr<  \
    VectorConstReference<T1, Size>,  \
    VectorConstReference<T2, Size>,  \
    AddFun<T1, T2>  \
  >,  \
  Size  \
>
add(const Vector<T1, Size>& lhs, const Vector<T2, Size>& rhs) {

    //test
    //std::cout << "operator add lhs(0):" << lhs(0) << " " << "rhs(0):" <<rhs(0) << std::endl;

    typedef BinaryExpr<  \
              VectorConstReference<T1, Size>,  \
              VectorConstReference<T2, Size>,  \
              AddFun<T1, T2>  \
            >  \
            expr;
    
    //expr testE(lhs, rhs);
    //std::cout << "operator add test Expr 0:" << testE(4) << std::endl;
    
    VectorExpr<expr, Size> vecE(expr(lhs.constRef(), rhs.constRef()));
    std::cout << "operator add test VectorExpr 0:" << vecE(0) << std::endl;

    VectorExpr<expr, Size> t(vecE);
    std::cout << "Reference vecE:" << t(0) << std::endl;
    

    return VectorExpr<expr, Size>(expr(lhs.constRef(), rhs.constRef()));
    //return vecE;
}

}  //namespace

#endif