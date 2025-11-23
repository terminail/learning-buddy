cmake_minimum_required(VERSION 3.10)
project(logical_operators_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(logical_operators_exercises src/logical_operators_exercises.cpp)

# Add library for the solution
add_library(logical_operators_solutions src/logical_operators_solutions.cpp)

# Add executable for basic tests
add_executable(test_logical_operators_basics test/test_logical_operators_basics.cpp)
target_link_libraries(test_logical_operators_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_logical_operators_practice test/test_logical_operators_practice.cpp)
target_link_libraries(test_logical_operators_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME logical_operators_basics_test COMMAND test_logical_operators_basics)
add_test(NAME logical_operators_practice_test COMMAND test_logical_operators_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_logical_operators_basics test_logical_operators_practice
    COMMENT "Running all logical operators tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_logical_operators_basics
    COMMENT "Running basic logical operators tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_logical_operators_practice
    COMMENT "Running practice logical operators tests with detailed output")