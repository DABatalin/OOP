project(lab1 VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 main.cpp time_converter.cpp)

enable_testing()

add_executable(lab1_tests tests01.cpp time_converter.cpp)
target_link_libraries(lab1_tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND lab1_tests)