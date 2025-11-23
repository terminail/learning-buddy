cmake_minimum_required(VERSION 3.10)
project(numeric_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(numeric_algorithms_exercises src/numeric_algorithms_exercises.cpp)

# Create the solutions library
add_library(numeric_algorithms_solutions src/numeric_algorithms_solutions.cpp)

# Create the basic test executable
add_executable(test_numeric_algorithms_basics test/test_numeric_algorithms_basics.cpp)

# Create the practice test executable
add_executable(test_numeric_algorithms_practice test/test_numeric_algorithms_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_numeric_algorithms_basics numeric_algorithms_exercises)
target_link_libraries(test_numeric_algorithms_practice numeric_algorithms_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_numeric_algorithms_basics GTest::GTest GTest::Main)
    target_link_libraries(test_numeric_algorithms_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_numeric_algorithms_basics
    COMMAND test_numeric_algorithms_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all numeric algorithms tests"
)

add_custom_target(run_basics
    COMMAND test_numeric_algorithms_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic numeric algorithms tests"
)

add_custom_target(run_practice
    COMMAND test_numeric_algorithms_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice numeric algorithms tests"
)