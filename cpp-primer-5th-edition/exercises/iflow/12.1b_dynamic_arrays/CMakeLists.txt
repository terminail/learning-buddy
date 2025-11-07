cmake_minimum_required(VERSION 3.10)
project(dynamic_arrays)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings for better code quality
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Find required packages with error handling
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
    message(FATAL_ERROR "Google Test not found. Please install Google Test to run tests.")
endif()

# Include directories
include_directories(include)

# Student exercise library
add_library(dynamic_arrays_exercises src/dynamic_arrays_exercises.cpp)

# Solution library
add_library(dynamic_arrays_solutions src/dynamic_arrays_solutions.cpp)

# Test executables
add_executable(test_dynamic_arrays_basics test/test_dynamic_arrays_basics.cpp)
target_link_libraries(test_dynamic_arrays_basics 
    dynamic_arrays_exercises 
    GTest::gtest 
    GTest::gtest_main)

add_executable(test_dynamic_arrays_practice test/test_dynamic_arrays_practice.cpp)
target_link_libraries(test_dynamic_arrays_practice 
    dynamic_arrays_exercises 
    GTest::gtest 
    GTest::gtest_main)

# Solution executable
add_executable(solution_dynamic_arrays src/dynamic_arrays_solutions.cpp)

# Enable testing
enable_testing()

# Add tests with labels for better organization
add_test(NAME test_basics COMMAND test_dynamic_arrays_basics)
set_property(TEST test_basics PROPERTY LABELS "basics")

add_test(NAME test_practice COMMAND test_dynamic_arrays_practice)
set_property(TEST test_practice PROPERTY LABELS "practice")

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_dynamic_arrays_basics test_dynamic_arrays_practice
    COMMENT "Running all tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_dynamic_arrays_basics
    COMMENT "Running basic tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_dynamic_arrays_practice
    COMMENT "Running practice tests with detailed output")