cmake_minimum_required(VERSION 3.10)
project(operator_precedence_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(operator_precedence_exercises src/operator_precedence_exercises.cpp)

# Add library for the solution
add_library(operator_precedence_solutions src/operator_precedence_solutions.cpp)

# Add executable for basic tests
add_executable(test_operator_precedence_basics test/test_operator_precedence_basics.cpp)
target_link_libraries(test_operator_precedence_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_operator_precedence_practice test/test_operator_precedence_practice.cpp)
target_link_libraries(test_operator_precedence_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME operator_precedence_basics_test COMMAND test_operator_precedence_basics)
add_test(NAME operator_precedence_practice_test COMMAND test_operator_precedence_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_operator_precedence_basics test_operator_precedence_practice
    COMMENT "Running all operator precedence tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_operator_precedence_basics
    COMMENT "Running basic operator precedence tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_operator_precedence_practice
    COMMENT "Running practice operator precedence tests with detailed output")