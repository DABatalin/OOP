project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab_4_lib ${SOURCES})
add_executable(lab4 main.cpp)

target_link_libraries(lab4 PRIVATE lab_4_lib)

enable_testing()

add_executable(lab4_tests ${TEST_DIR}/tests01.cpp ${INCLUDE_DIR}/hexagon.h ${INCLUDE_DIR}/pentagon.h ${INCLUDE_DIR}/rhombus.h ${INCLUDE_DIR}/array.h ${INCLUDE_DIR}/methods.h)
target_link_libraries(lab4_tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND lab4_tests)