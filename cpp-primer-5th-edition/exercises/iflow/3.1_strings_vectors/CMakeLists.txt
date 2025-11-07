cmake_minimum_required(VERSION 3.10)
project(strings_vectors)

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
add_library(strings_vectors_exercises src/strings_vectors_exercises.cpp)

# Solution library
add_library(strings_vectors_solutions src/strings_vectors_solutions.cpp)

# Test executables
add_executable(test_strings_vectors_basics test/test_strings_vectors_basics.cpp)
target_link_libraries(test_strings_vectors_basics 
    strings_vectors_exercises 
    GTest::gtest 
    GTest::gtest_main)

add_executable(test_strings_vectors_practice test/test_strings_vectors_practice.cpp)
target_link_libraries(test_strings_vectors_practice 
    strings_vectors_exercises 
    GTest::gtest 
    GTest::gtest_main)

# Solution executable
add_executable(solution_strings_vectors src/strings_vectors_solutions.cpp)

# Enable testing
enable_testing()

# Add tests with labels for better organization
add_test(NAME test_basics COMMAND test_strings_vectors_basics)
set_property(TEST test_basics PROPERTY LABELS "basics")

add_test(NAME test_practice COMMAND test_strings_vectors_practice)
set_property(TEST test_practice PROPERTY LABELS "practice")

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_strings_vectors_basics test_strings_vectors_practice
    COMMENT "Running all tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_strings_vectors_basics
    COMMENT "Running basic tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_strings_vectors_practice
    COMMENT "Running practice tests with detailed output")