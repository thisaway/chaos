project(Geometry)

add_library(${PROJECT_NAME}  ${CHAOS_LIB_TYPE}
            include/Conception2d.h
            )

target_include_directories(${PROJECT_NAME}  
                        PUBLIC ${PROJECT_SOURCE_DIR}/include
                        PUBLIC ${PROJECT_SOURCE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)