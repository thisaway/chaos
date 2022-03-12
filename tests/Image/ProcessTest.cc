//ProcessTest.cc
#include "gtest/gtest.h"
#include "Image.h"
#include "Process.h"

#include <iostream>

namespace {
using namespace chaos::image;

class ProcessTest : public testing::Test {

protected:
  void SetUp() override {
      img1 = loadImage("/home/tob/Desktop/chaos/tests/Image/testData/happy.jpg");
  }

protected:
  Image img1;
};

TEST_F(ProcessTest, loadImage) {

  EXPECT_TRUE(img1.width() == 1920);
  EXPECT_TRUE(img1.height() == 1276);
}

TEST_F(ProcessTest, saveImage) {

    bool success = saveImage("/home/tob/Desktop/chaos/tests/Image/testData/happy_test.jpg",  \
      img1);
    EXPECT_TRUE(success == 1);
}

}  //namespace