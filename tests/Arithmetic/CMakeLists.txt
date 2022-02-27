add_executable(testArithmetic
  VectorTest.cc
  MatrixTest.cc
)

target_link_libraries(testArithmetic Arithmetic)
create_test(testArithmetic)