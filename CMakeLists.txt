cmake_minimum_required(VERSION 3.10)
project(raytracing)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(MAKE_DIRECTORY "bin")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src/)

add_executable(rayTest src/app/rayTest.cpp)

# Locate GTest
find_package(GTest)

if(GTEST_FOUND)
    message(STATUS "GTest found. Building tests.")
    include_directories(${GTEST_INCLUDE_DIRS})
    include_directories(${PROJECT_SOURCE_DIR}/tests)
    add_executable(vectorTest "tests/vectorTest.cpp")
    target_link_libraries(vectorTest ${GTEST_LIBRARIES} pthread)
else()
    message(WARNING "GTest not found. Will not build tests.")
endif(GTEST_FOUND)