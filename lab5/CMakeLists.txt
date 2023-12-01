project(lab5 VERSION 0.1.0 LANGUAGES C CXX)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lab5_ns/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lab5_ns/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)

add_library(lab_5_lib ${SOURCES})
add_executable(lab5 main.cpp)

target_link_libraries(lab5 PRIVATE lab_5_lib)

include(FetchContent)
FetchContent_Declare(
	gtest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(gtest)

add_executable(lab5_tests ${TEST_DIR}/tests01.cpp ${INCLUDE_DIR}/allocator.h ${INCLUDE_DIR}/functions.h ${INCLUDE_DIR}/queue.h)
target_link_libraries(lab5_tests GTest::gtest_main)

include(GoogleTest)