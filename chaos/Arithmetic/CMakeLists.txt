project(Arithmetic)

add_library(${PROJECT_NAME}  ${CHAOS_LIB_TYPE}
            Expr/BinaryExpr.h
            Expr/VectorExpr.h
            Expr/VectorExprFun.h
            Expr/VectorExprOperator.h
            Expr/MatrixExpr.h
            Expr/MatrixExprFun.h
            Expr/MatrixExprOperator.h
            Arithmetic.h
            ArithmeticBase.h
            BinaryFun.h
            Vector.h
            VectorFun.h
            VectorOperator.h
            Matrix.h
            MatrixFun.h
            MatrixOperator.h
            TypePromotion.h)

target_include_directories(${PROJECT_NAME}  
                        PUBLIC ${PROJECT_SOURCE_DIR}/Expr
                        PUBLIC ${PROJECT_SOURCE_DIR})

set_target_properties(Arithmetic PROPERTIES LINKER_LANGUAGE CXX)