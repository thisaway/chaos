//MatrixTest.cc
#include "gtest/gtest.h"
#include "Matrix.h"
#include "MatrixExpr.h"

namespace {

class MatrixTest : public testing::Test {

protected:
  void SetUp() override {

      mat1 << 1, 1, 1, 1, 1, 1;
      mat2 << 1, 2, 3, 4, 5, 6;
      mat3 << 6, 7, 8, 9, 10, 11;
      mat4 << 2, 2, 2, 2, 2, 2;
  }

protected:
  chaos::Matrix<int, 2, 3> mat1;
  chaos::Matrix<int, 2, 3> mat2;
  chaos::Matrix<int, 2, 3> mat3;
  chaos::Matrix<int, 2, 3> mat4;
};

TEST_F(MatrixTest, attribitus) {

  EXPECT_TRUE(mat1.size == 6);
  EXPECT_TRUE(mat1.rows == 2);
  EXPECT_TRUE(mat1.cols == 3);
  EXPECT_TRUE(mat2.size == 6);
  EXPECT_TRUE(mat2.rows == 2);
  EXPECT_TRUE(mat2.cols == 3);
}

//operator <<&&, test
TEST_F(MatrixTest, operatorInit) {
  int* mat1Ptr = mat1.data();
  int* mat2Ptr = mat2.data();
  
  //mat1 init test;
  EXPECT_TRUE(*(mat1Ptr+0) == 1);
  EXPECT_TRUE(*(mat1Ptr+1) == 1);
  EXPECT_TRUE(*(mat1Ptr+2) == 1);
  EXPECT_TRUE(*(mat1Ptr+3) == 1);
  EXPECT_TRUE(*(mat1Ptr+4) == 1);
  EXPECT_TRUE(*(mat1Ptr+5) == 1);

  //mat2 init test;
  EXPECT_TRUE(*(mat2Ptr+0) == 1);
  EXPECT_TRUE(*(mat2Ptr+1) == 2);
  EXPECT_TRUE(*(mat2Ptr+2) == 3);
  EXPECT_TRUE(*(mat2Ptr+3) == 4);
  EXPECT_TRUE(*(mat2Ptr+4) == 5);
  EXPECT_TRUE(*(mat2Ptr+5) == 6);
}

TEST_F(MatrixTest, construct) {

  chaos::Matrix<int, 2, 3> matConstruct1 = mat1;
  EXPECT_TRUE(matConstruct1(0, 0) == 1);
  EXPECT_TRUE(matConstruct1(0, 1) == 1);
  EXPECT_TRUE(matConstruct1(0, 2) == 1);
  EXPECT_TRUE(matConstruct1(1, 0) == 1);
  EXPECT_TRUE(matConstruct1(1, 1) == 1);
  EXPECT_TRUE(matConstruct1(1, 2) == 1);

  chaos::Matrix<int, 2, 3> matConstruct2(mat2);
  EXPECT_TRUE(matConstruct2(0, 0) == 1);
  EXPECT_TRUE(matConstruct2(0, 1) == 2);
  EXPECT_TRUE(matConstruct2(0, 2) == 3);
  EXPECT_TRUE(matConstruct2(1, 0) == 4);
  EXPECT_TRUE(matConstruct2(1, 1) == 5);
  EXPECT_TRUE(matConstruct2(1, 2) == 6);
}

TEST_F(MatrixTest, addMatrix) {

  //test Matrix+Matrix
  chaos::Matrix<int, 2, 3> matSum1;
  matSum1 = mat1 + mat2;
  EXPECT_TRUE(matSum1(0, 0) == 2);
  EXPECT_TRUE(matSum1(0, 1) == 3);
  EXPECT_TRUE(matSum1(0, 2) == 4);
  EXPECT_TRUE(matSum1(1, 0) == 5);
  EXPECT_TRUE(matSum1(1, 1) == 6);
  EXPECT_TRUE(matSum1(1, 2) == 7);
  
  //test MatrixExpr+Matrix
  chaos::Matrix<int, 2, 3> matSum2;
  matSum2 = mat1 + mat2 + mat3;
  EXPECT_TRUE(matSum2(0, 0) == 8);
  EXPECT_TRUE(matSum2(0, 1) == 10);
  EXPECT_TRUE(matSum2(0, 2) == 12);
  EXPECT_TRUE(matSum2(1, 0) == 14);
  EXPECT_TRUE(matSum2(1, 1) == 16);
  EXPECT_TRUE(matSum2(1, 2) == 18);

  //test MatrixExpr+MatrixExpr
  chaos::Matrix<int, 2, 3> matSum3;
  matSum3 = (mat1 + mat2) + (mat3 + mat4);
  EXPECT_TRUE(matSum3(0, 0) == 10);
  EXPECT_TRUE(matSum3(0, 1) == 12);
  EXPECT_TRUE(matSum3(0, 2) == 14);
  EXPECT_TRUE(matSum3(1, 0) == 16);
  EXPECT_TRUE(matSum3(1, 1) == 18);
  EXPECT_TRUE(matSum3(1, 2) == 20);

}

TEST_F(MatrixTest, subMatrix) {

  //test Matrix-Matrix
  chaos::Matrix<int, 2, 3> matDiff1;
  matDiff1 = mat2 - mat1;
  EXPECT_TRUE(matDiff1(0, 0) == 0);
  EXPECT_TRUE(matDiff1(0, 1) == 1);
  EXPECT_TRUE(matDiff1(0, 2) == 2);
  EXPECT_TRUE(matDiff1(1, 0) == 3);
  EXPECT_TRUE(matDiff1(1, 1) == 4);
  EXPECT_TRUE(matDiff1(1, 2) == 5);
  
  //test MatrixExpr-Matrix
  chaos::Matrix<int, 2, 3> matDiff2;
  matDiff2 = mat3 - mat2 - mat1;
  EXPECT_TRUE(matDiff2(0, 0) == 4);
  EXPECT_TRUE(matDiff2(0, 1) == 4);
  EXPECT_TRUE(matDiff2(0, 2) == 4);
  EXPECT_TRUE(matDiff2(1, 0) == 4);
  EXPECT_TRUE(matDiff2(1, 1) == 4);
  EXPECT_TRUE(matDiff2(1, 2) == 4);

  //test MatrixExpr-MatrixExpr
  chaos::Matrix<int, 2, 3> matDiff3;
  matDiff3 = (mat3 - mat2) - (mat4 - mat1);
  EXPECT_TRUE(matDiff3(0, 0) == 4);
  EXPECT_TRUE(matDiff3(0, 1) == 4);
  EXPECT_TRUE(matDiff3(0, 2) == 4);
  EXPECT_TRUE(matDiff3(1, 0) == 4);
  EXPECT_TRUE(matDiff3(1, 1) == 4);
  EXPECT_TRUE(matDiff3(1, 2) == 4);

}

TEST_F(MatrixTest, mulMatrix) {

  //test Matrix*Matrix
  chaos::Matrix<int, 2, 3> matProd1;
  matProd1 = mat2 * mat1;
  EXPECT_TRUE(matProd1(0, 0) == 1);
  EXPECT_TRUE(matProd1(0, 1) == 2);
  EXPECT_TRUE(matProd1(0, 2) == 3);
  EXPECT_TRUE(matProd1(1, 0) == 4);
  EXPECT_TRUE(matProd1(1, 1) == 5);
  EXPECT_TRUE(matProd1(1, 2) == 6);
  
  //test MatrixExpr*Matrix
  chaos::Matrix<int, 2, 3> matProd2;
  matProd2 = mat3 * mat2 * mat1;
  EXPECT_TRUE(matProd2(0, 0) == 6);
  EXPECT_TRUE(matProd2(0, 1) == 14);
  EXPECT_TRUE(matProd2(0, 2) == 24);
  EXPECT_TRUE(matProd2(1, 0) == 36);
  EXPECT_TRUE(matProd2(1, 1) == 50);
  EXPECT_TRUE(matProd2(1, 2) == 66);

  //test MatrixExpr*MatrixExpr
  chaos::Matrix<int, 2, 3> matProd3;
  matProd3 = (mat3 * mat2) * (mat4 * mat1);
  EXPECT_TRUE(matProd3(0, 0) == 12);
  EXPECT_TRUE(matProd3(0, 1) == 28);
  EXPECT_TRUE(matProd3(0, 2) == 48);
  EXPECT_TRUE(matProd3(1, 0) == 72);
  EXPECT_TRUE(matProd3(1, 1) == 100);
  EXPECT_TRUE(matProd3(1, 2) == 132);

}

TEST_F(MatrixTest, divMatrix) {

  //test Matrix/Matrix
  chaos::Matrix<int, 2, 3> matQuot1;
  matQuot1 = mat2 / mat1;
  EXPECT_TRUE(matQuot1(0, 0) == 1);
  EXPECT_TRUE(matQuot1(0, 1) == 2);
  EXPECT_TRUE(matQuot1(0, 2) == 3);
  EXPECT_TRUE(matQuot1(1, 0) == 4);
  EXPECT_TRUE(matQuot1(1, 1) == 5);
  EXPECT_TRUE(matQuot1(1, 2) == 6);
  
  //test MatrixExpr/Matrix
  chaos::Matrix<int, 2, 3> matQuot2;
  matQuot2 = mat2 / mat1 / mat1;
  EXPECT_TRUE(matQuot2(0, 0) == 1);
  EXPECT_TRUE(matQuot2(0, 1) == 2);
  EXPECT_TRUE(matQuot2(0, 2) == 3);
  EXPECT_TRUE(matQuot2(1, 0) == 4);
  EXPECT_TRUE(matQuot2(1, 1) == 5);
  EXPECT_TRUE(matQuot2(1, 2) == 6);

  //test MatrixExpr/MatrixExpr
  chaos::Matrix<int, 2, 3> matQuot3;
  matQuot3 = (mat2 / mat1) / (mat2 / mat1);
  EXPECT_TRUE(matQuot3(0, 0) == 1);
  EXPECT_TRUE(matQuot3(0, 1) == 1);
  EXPECT_TRUE(matQuot3(0, 2) == 1);
  EXPECT_TRUE(matQuot3(1, 0) == 1);
  EXPECT_TRUE(matQuot3(1, 1) == 1);
  EXPECT_TRUE(matQuot3(1, 2) == 1);

}

}  //namespace