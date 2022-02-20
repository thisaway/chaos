add_executable(testArithmetic
  VectorTest.cc
)

target_link_libraries(testArithmetic Arithmetic)
create_test(testArithmetic)