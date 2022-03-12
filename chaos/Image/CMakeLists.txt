project(Image)

INCLUDE_DIRECTORIES(/home/tob/Downloads/FreeImage3180/FreeImage/Dist)

add_library(${PROJECT_NAME}  ${CHAOS_LIB_TYPE}
            src/Image.cc  src/Process.cc
            src/Drawer.cc
            )

target_link_libraries(${PROJECT_NAME}
                      PUBLIC Geometry
                      PUBLIC /home/tob/Downloads/FreeImage3180/FreeImage/Dist/libfreeimage-3.18.0.so)

target_include_directories(${PROJECT_NAME}  
                        PUBLIC ${PROJECT_SOURCE_DIR}/include)