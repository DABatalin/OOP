cmake_minimum_required(VERSION 3.0.0)
project(huggy_vaggy VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(huggy_vaggy main.cpp time_converter.cpp)

enable_testing()

add_executable(tests01 tests01.cpp time_converter.cpp)
target_link_libraries(tests01 ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests01)