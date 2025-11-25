cmake_minimum_required(VERSION 3.10)
project(scope_and_lifetime_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(scope_and_lifetime_exercises src/scope_and_lifetime_exercises.cpp)

# Add library for the solution
add_library(scope_and_lifetime_solutions src/scope_and_lifetime_solutions.cpp)

# Add executable for basic tests
add_executable(test_scope_and_lifetime_basics test/test_scope_and_lifetime_basics.cpp)
target_link_libraries(test_scope_and_lifetime_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_scope_and_lifetime_practice test/test_scope_and_lifetime_practice.cpp)
target_link_libraries(test_scope_and_lifetime_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME scope_and_lifetime_basics_test COMMAND test_scope_and_lifetime_basics)
add_test(NAME scope_and_lifetime_practice_test COMMAND test_scope_and_lifetime_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_scope_and_lifetime_basics test_scope_and_lifetime_practice
    COMMENT "Running all scope and lifetime tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_scope_and_lifetime_basics
    COMMENT "Running basic scope and lifetime tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_scope_and_lifetime_practice
    COMMENT "Running practice scope and lifetime tests with detailed output")