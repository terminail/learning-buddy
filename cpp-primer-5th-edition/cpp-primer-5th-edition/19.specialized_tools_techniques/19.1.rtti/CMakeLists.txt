cmake_minimum_required(VERSION 3.10)
project(rtti)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(rtti_exercises src/rtti_exercises.cpp)

# Create the solutions library
add_library(rtti_solutions src/rtti_solutions.cpp)

# Create the basic test executable
add_executable(test_rtti_basics test/test_rtti_basics.cpp)

# Create the practice test executable
add_executable(test_rtti_practice test/test_rtti_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_rtti_basics rtti_exercises)
target_link_libraries(test_rtti_practice rtti_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_rtti_basics GTest::GTest GTest::Main)
    target_link_libraries(test_rtti_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_rtti_basics
    COMMAND test_rtti_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all RTTI tests"
)

add_custom_target(run_basics
    COMMAND test_rtti_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic RTTI tests"
)

add_custom_target(run_practice
    COMMAND test_rtti_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice RTTI tests"
)