cmake_minimum_required(VERSION 2.6)

project(DemoprojectExtendedWithCodeCoverage)

add_definitions(-fprofile-arcs -ftest-coverage)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)


#Let us modify it a bit!

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(myLib STATIC whattotest.cpp)
target_include_directories(myLib PUBLIC .)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_include_directories(runTests PUBLIC .)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread myLib)
