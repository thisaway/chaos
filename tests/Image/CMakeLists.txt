add_executable(testImage
  ImageTest.cc
  ProcessTest.cc
  DrawerTest.cc
)

target_link_libraries(testImage Image Geometry)
create_test(testImage)