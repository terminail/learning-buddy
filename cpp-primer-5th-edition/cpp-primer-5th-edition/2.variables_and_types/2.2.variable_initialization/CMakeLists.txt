cmake_minimum_required(VERSION 3.10)
project(variable_initialization_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(variable_initialization_exercises src/variable_initialization_exercises.cpp)

# Add library for the solution
add_library(variable_initialization_solutions src/variable_initialization_solutions.cpp)

# Add executable for basic tests
add_executable(test_variable_initialization_basics test/test_variable_initialization_basics.cpp)
target_link_libraries(test_variable_initialization_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_variable_initialization_practice test/test_variable_initialization_practice.cpp)
target_link_libraries(test_variable_initialization_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME variable_initialization_basics_test COMMAND test_variable_initialization_basics)
add_test(NAME variable_initialization_practice_test COMMAND test_variable_initialization_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_variable_initialization_basics test_variable_initialization_practice
    COMMENT "Running all variable initialization tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_variable_initialization_basics
    COMMENT "Running basic variable initialization tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_variable_initialization_practice
    COMMENT "Running practice variable initialization tests with detailed output")