//VectorTest.cc
#include "gtest/gtest.h"
#include "Vector.h"
#include "VectorExpr.h"

#include <iostream>

namespace {

class VectorTest : public testing::Test {

protected:
  void SetUp() override {
      vec1 << 1, 1, 1, 1, 1;
      vec2 << 1, 2, 3, 4, 5;
  }

protected:
  chaos::Vector<int, 5> vec1;
  chaos::Vector<int, 5> vec2;
};

TEST_F(VectorTest, sizeFun) {

  EXPECT_TRUE(vec1.size == 5);
  EXPECT_TRUE(vec2.size == 5);
}

//operator <<&&, test
TEST_F(VectorTest, operatorInit) {
  int* vec1Ptr = vec1.data();
  int* vec2Ptr = vec2.data();
  
  //vec1 init test;
  EXPECT_TRUE(*(vec1Ptr+0) == 1);
  EXPECT_TRUE(*(vec1Ptr+1) == 1);
  EXPECT_TRUE(*(vec1Ptr+2) == 1);
  EXPECT_TRUE(*(vec1Ptr+3) == 1);
  EXPECT_TRUE(*(vec1Ptr+4) == 1);

  //vec2 init test;
  EXPECT_TRUE(*(vec2Ptr+0) == 1);
  EXPECT_TRUE(*(vec2Ptr+1) == 2);
  EXPECT_TRUE(*(vec2Ptr+2) == 3);
  EXPECT_TRUE(*(vec2Ptr+3) == 4);
  EXPECT_TRUE(*(vec2Ptr+4) == 5);
}

TEST_F(VectorTest, construct) {

  chaos::Vector<int, 5> vecConstruct1 = vec1;
  EXPECT_TRUE(vecConstruct1(0) == 1);
  EXPECT_TRUE(vecConstruct1(1) == 1);
  EXPECT_TRUE(vecConstruct1(2) == 1);
  EXPECT_TRUE(vecConstruct1(3) == 1);
  EXPECT_TRUE(vecConstruct1(4) == 1);

  chaos::Vector<int, 5> vecConstruct2(vec2);
  EXPECT_TRUE(vecConstruct2(0) == 1);
  EXPECT_TRUE(vecConstruct2(1) == 2);
  EXPECT_TRUE(vecConstruct2(2) == 3);
  EXPECT_TRUE(vecConstruct2(3) == 4);
  EXPECT_TRUE(vecConstruct2(4) == 5);
}

TEST_F(VectorTest, addVector) {

  chaos::Vector<int, 5> vecSum1;
  //vecSum1 = vec1 + vec2;
  chaos::VectorExpr<  \
    chaos::BinaryExpr<  \
      chaos::VectorConstReference<int, 5>,  \
      chaos::VectorConstReference<int, 5>,  \
      chaos::AddFun<int, int>  \
    >,  \
    5  \
  > addVecExp(chaos::add(vec1, vec2));
  std::cout << "addVecExp:" << addVecExp(0) << std::endl;
  std::cout << "addVecExp:" << addVecExp(1) << std::endl;
  std::cout << "addVecExp:" << addVecExp(2) << std::endl;
  std::cout << "addVecExp:" << addVecExp(3) << std::endl;
  std::cout << "addVecExp:" << addVecExp(4) << std::endl;

  vecSum1 = vec1 + vec2;
  std::cout << "vecSum1:" << vecSum1(0) << std::endl;
  std::cout << "vecSum1:" << vecSum1(1) << std::endl;
  std::cout << "vecSum1:" << vecSum1(2) << std::endl;
  std::cout << "vecSum1:" << vecSum1(3) << std::endl;
  std::cout << "vecSum1:" << vecSum1(4) << std::endl;
  EXPECT_TRUE(vecSum1(0) == 2);
  EXPECT_TRUE(vecSum1(1) == 3);
  EXPECT_TRUE(vecSum1(2) == 4);
  EXPECT_TRUE(vecSum1(3) == 5);
  EXPECT_TRUE(vecSum1(4) == 6);
}

}  //namespace