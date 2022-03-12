//ProcessTest.cc
#include "gtest/gtest.h"
#include "Image.h"
#include "Process.h"

#include <iostream>
#include <cstring>

namespace {
using namespace chaos::image;

class ImageTest : public testing::Test {

protected:
  void SetUp() override {
      img1 = Image(640, 480, 3);
  }

protected:
  Image img1;
};

TEST_F(ImageTest, attributes) {

  EXPECT_TRUE(img1.width() == 640);
  EXPECT_TRUE(img1.height() == 480);
  EXPECT_TRUE(img1.channels() == 3);
}

TEST_F(ImageTest, operator) {
  img1(0, 0, 0) = 0;
  img1(0, 0, 1) = 0;
  img1(0, 0, 2) = 0;
  img1(1, 0, 0) = 0;
  img1(1, 0, 1) = 0;
  img1(1, 0, 2) = 0;
  img1(0, 1, 0) = 0;
  img1(0, 1, 1) = 0;
  img1(0, 1, 2) = 0;
  img1(1, 1, 0) = 0;
  img1(1, 1, 1) = 0;
  img1(1, 1, 2) = 0;
  
  EXPECT_TRUE(img1(0, 0, 0) == 0);
  EXPECT_TRUE(img1(100, 100, 2) == 255);
  EXPECT_TRUE(img1(300, 300, 2) == 255);
  bool success = saveImage("/home/tob/Desktop/chaos/tests/Image/testData/onePoint.jpg",  \
      img1);
  EXPECT_TRUE(success == 1);
}

TEST_F(ImageTest, line) {
    uint8_t* halfPtr = img1.data() + (img1.width() * img1.height() * img1.channels() / 2);
    memset(halfPtr, 0, sizeof(uint8_t) * img1.width() * img1.height() * img1.channels() / 2);
    bool success = saveImage("/home/tob/Desktop/chaos/tests/Image/testData/half.jpg",  \
      img1);
    EXPECT_TRUE(success == 1);

}

TEST_F(ImageTest, saveImage) {

    bool success = saveImage("/home/tob/Desktop/chaos/tests/Image/testData/null.jpg",  \
      img1);
    EXPECT_TRUE(success == 1);
}

}  //namespace