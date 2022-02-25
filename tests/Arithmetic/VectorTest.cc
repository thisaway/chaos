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
      vec3 << 6, 7, 8, 9, 10;
      vec4 << 2, 2, 2, 2, 2;
  }

protected:
  chaos::Vector<int, 5> vec1;
  chaos::Vector<int, 5> vec2;
  chaos::Vector<int, 5> vec3;
  chaos::Vector<int, 5> vec4;
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

  //test Vector+Vector
  chaos::Vector<int, 5> vecSum1;
  vecSum1 = vec1 + vec2;
  EXPECT_TRUE(vecSum1(0) == 2);
  EXPECT_TRUE(vecSum1(1) == 3);
  EXPECT_TRUE(vecSum1(2) == 4);
  EXPECT_TRUE(vecSum1(3) == 5);
  EXPECT_TRUE(vecSum1(4) == 6);
  
  //test VectorExpr+Vector
  chaos::Vector<int, 5> vecSum2;
  vecSum2 = vec1 + vec2 + vec3;
  EXPECT_TRUE(vecSum2(0) == 8);
  EXPECT_TRUE(vecSum2(1) == 10);
  EXPECT_TRUE(vecSum2(2) == 12);
  EXPECT_TRUE(vecSum2(3) == 14);
  EXPECT_TRUE(vecSum2(4) == 16);

  //test VectorExpr+VectorExpr
  chaos::Vector<int, 5> vecSum3;
  vecSum3 = (vec1 + vec2) + (vec3 + vec4);
  EXPECT_TRUE(vecSum3(0) == 10);
  EXPECT_TRUE(vecSum3(1) == 12);
  EXPECT_TRUE(vecSum3(2) == 14);
  EXPECT_TRUE(vecSum3(3) == 16);
  EXPECT_TRUE(vecSum3(4) == 18);

}

TEST_F(VectorTest, subVector) {

  //test Vector-Vector
  chaos::Vector<int, 5> vecDiff1;
  vecDiff1 = vec2 - vec1;
  EXPECT_TRUE(vecDiff1(0) == 0);
  EXPECT_TRUE(vecDiff1(1) == 1);
  EXPECT_TRUE(vecDiff1(2) == 2);
  EXPECT_TRUE(vecDiff1(3) == 3);
  EXPECT_TRUE(vecDiff1(4) == 4);
  
  //test VectorExpr-Vector
  chaos::Vector<int, 5> vecDiff2;
  vecDiff2 = vec3 - vec2 - vec1;
  EXPECT_TRUE(vecDiff2(0) == 4);
  EXPECT_TRUE(vecDiff2(1) == 4);
  EXPECT_TRUE(vecDiff2(2) == 4);
  EXPECT_TRUE(vecDiff2(3) == 4);
  EXPECT_TRUE(vecDiff2(4) == 4);

  //test VectorExpr-VectorExpr
  chaos::Vector<int, 5> vecDiff3;
  vecDiff3 = (vec3 - vec2) - (vec4 - vec1);
  EXPECT_TRUE(vecDiff3(0) == 4);
  EXPECT_TRUE(vecDiff3(1) == 4);
  EXPECT_TRUE(vecDiff3(2) == 4);
  EXPECT_TRUE(vecDiff3(3) == 4);
  EXPECT_TRUE(vecDiff3(4) == 4);

}

TEST_F(VectorTest, mulVector) {

  //test Vector*Vector
  chaos::Vector<int, 5> vecProd1;
  vecProd1 = vec2 * vec1;
  EXPECT_TRUE(vecProd1(0) == 1);
  EXPECT_TRUE(vecProd1(1) == 2);
  EXPECT_TRUE(vecProd1(2) == 3);
  EXPECT_TRUE(vecProd1(3) == 4);
  EXPECT_TRUE(vecProd1(4) == 5);
  
  //test VectorExpr*Vector
  chaos::Vector<int, 5> vecProd2;
  vecProd2 = vec3 * vec2 * vec1;
  EXPECT_TRUE(vecProd2(0) == 6);
  EXPECT_TRUE(vecProd2(1) == 14);
  EXPECT_TRUE(vecProd2(2) == 24);
  EXPECT_TRUE(vecProd2(3) == 36);
  EXPECT_TRUE(vecProd2(4) == 50);

  //test VectorExpr*VectorExpr
  chaos::Vector<int, 5> vecProd3;
  vecProd3 = (vec3 * vec2) * (vec4 * vec1);
  EXPECT_TRUE(vecProd3(0) == 12);
  EXPECT_TRUE(vecProd3(1) == 28);
  EXPECT_TRUE(vecProd3(2) == 48);
  EXPECT_TRUE(vecProd3(3) == 72);
  EXPECT_TRUE(vecProd3(4) == 100);

}

TEST_F(VectorTest, divVector) {

  //test Vector/Vector
  chaos::Vector<int, 5> vecQuot1;
  vecQuot1 = vec2 / vec1;
  EXPECT_TRUE(vecQuot1(0) == 1);
  EXPECT_TRUE(vecQuot1(1) == 2);
  EXPECT_TRUE(vecQuot1(2) == 3);
  EXPECT_TRUE(vecQuot1(3) == 4);
  EXPECT_TRUE(vecQuot1(4) == 5);
  
  //test VectorExpr/Vector
  chaos::Vector<int, 5> vecQuot2;
  vecQuot2 = vec2 / vec1 / vec1;
  EXPECT_TRUE(vecQuot2(0) == 1);
  EXPECT_TRUE(vecQuot2(1) == 2);
  EXPECT_TRUE(vecQuot2(2) == 3);
  EXPECT_TRUE(vecQuot2(3) == 4);
  EXPECT_TRUE(vecQuot2(4) == 5);

  //test VectorExpr/VectorExpr
  chaos::Vector<int, 5> vecQuot3;
  vecQuot3 = (vec2 / vec1) / (vec2 / vec1);
  EXPECT_TRUE(vecQuot3(0) == 1);
  EXPECT_TRUE(vecQuot3(1) == 1);
  EXPECT_TRUE(vecQuot3(2) == 1);
  EXPECT_TRUE(vecQuot3(3) == 1);
  EXPECT_TRUE(vecQuot3(4) == 1);

}

}  //namespace