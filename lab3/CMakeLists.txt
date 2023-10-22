cmake_minimum_required(VERSION 3.0.0)
project(lab3 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab_3_lib ${SOURCES})
add_executable(lab3 main.cpp)

target_link_libraries(lab3 PRIVATE lab_3_lib)

enable_testing()

add_executable(lab3_tests ${TEST_DIR}/tests01.cpp ${SOURCE_DIR}/hexagon.cpp ${SOURCE_DIR}/pentagon.cpp ${SOURCE_DIR}/rhombus.cpp ${SOURCE_DIR}/array.cpp)
target_link_libraries(lab3_tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND lab3_tests)