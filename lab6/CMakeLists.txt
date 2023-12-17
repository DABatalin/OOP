project(lab6)

add_compile_options(-g)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
add_library(lab6_lib ${SOURCES})

add_executable(lab6_exe main.cpp)
target_link_libraries(lab6_exe PRIVATE lab6_lib)

enable_testing()

add_executable(lab6_test ${TEST_DIR}/tests01.cpp)
target_link_libraries(lab6_test PRIVATE lab6_lib ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND lab6_test)