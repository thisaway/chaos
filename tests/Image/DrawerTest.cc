//DrawerTest.cc
#include "gtest/gtest.h"
#include "Image.h"
#include "Process.h"
#include "Drawer.h"

#include <iostream>

namespace {
using namespace chaos::image;
using namespace chaos::geo;

class DrawerTest : public testing::Test {

protected:
  void SetUp() override {
      img1 = Image(200, 200, 3);
      drawer1.setColor(red);
      drawer1.setThickness(1);

  }

protected:
  Image img1;
  Drawer drawer1;
};

TEST_F(DrawerTest, attributes) {

  //todo
}

TEST_F(DrawerTest, drawLine) {
    
    bool lineSuccess = drawer1.drawLine(img1, Point2i(0, 0), Point2i(199, 199));
    bool saveSuccess = saveImage("/home/tob/Desktop/chaos/tests/Image/testData/drawLine_test.jpg",  \
      img1);
    
    EXPECT_TRUE(lineSuccess == 1);
    EXPECT_TRUE(saveSuccess == 1);
}

}  //namespace