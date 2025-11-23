cmake_minimum_required(VERSION 3.10)
project(exercise_name)

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
add_library(exercise_name_exercises src/exercise_name_exercises.cpp)

# Solution library
add_library(exercise_name_solutions src/exercise_name_solutions.cpp)

# Function exercises library (for chapters 1-4)
add_library(function_exercises src/function_exercises.cpp)

# Function solutions library
add_library(function_solutions src/function_solutions.cpp)

# Test executables for class-based exercises
add_executable(test_exercise_name_basics test/test_exercise_name_basics.cpp)
target_link_libraries(test_exercise_name_basics 
    exercise_name_exercises 
    GTest::gtest 
    GTest::gtest_main)

add_executable(test_exercise_name_practice test/test_exercise_name_practice.cpp)
target_link_libraries(test_exercise_name_practice 
    exercise_name_exercises 
    GTest::gtest 
    GTest::gtest_main)

# Test executable for function-based exercises
add_executable(test_function_basics test/test_function_basics.cpp)
target_link_libraries(test_function_basics 
    function_exercises 
    GTest::gtest 
    GTest::gtest_main)

# Solution executables
add_executable(solution_exercise_name src/exercise_name_solutions.cpp)
add_executable(solution_function_exercises src/function_solutions.cpp)

# Enable testing
enable_testing()

# Add tests with labels for better organization
add_test(NAME test_basics COMMAND test_exercise_name_basics)
set_property(TEST test_basics PROPERTY LABELS "basics")

add_test(NAME test_practice COMMAND test_exercise_name_practice)
set_property(TEST test_practice PROPERTY LABELS "practice")

add_test(NAME test_function_basics COMMAND test_function_basics)
set_property(TEST test_function_basics PROPERTY LABELS "function")

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_exercise_name_basics test_exercise_name_practice test_function_basics
    COMMENT "Running all tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_exercise_name_basics
    COMMENT "Running basic tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_exercise_name_practice
    COMMENT "Running practice tests with detailed output")

# Custom target for running function tests only
add_custom_target(run_function
    COMMAND ${CMAKE_CTEST_COMMAND} -L function --output-on-failure
    DEPENDS test_function_basics
    COMMENT "Running function tests with detailed output")

# Customization Instructions:
# 1. Update project name: project(your_exercise_name)
# 2. Update library names: exercise_name_exercises → your_exercise_exercises
# 3. Update executable names: test_exercise_name_basics → test_your_exercise_basics
# 4. Update target link libraries accordingly
#
# Example customization for string_basics exercise:
# project(string_basics)
# add_library(string_basics_exercises src/string_basics_exercises.cpp)
# add_library(string_basics_solutions src/string_basics_solutions.cpp)
# add_executable(test_string_basics_basics test/test_string_basics_basics.cpp)
# add_executable(test_string_basics_practice test/test_string_basics_practice.cpp)