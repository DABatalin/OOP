project(lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-g)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
add_library(lab7_lib ${SOURCES})
add_executable(lab7_exe main.cpp)
target_link_libraries(lab7_exe PRIVATE lab7_lib)

enable_testing()

add_executable(lab7_test ${TEST_DIR}/tests01.cpp)
target_link_libraries(lab7_test PRIVATE lab7_lib ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND lab7_test)