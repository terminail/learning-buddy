cmake_minimum_required(VERSION 3.10)
project(hello_world)

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

# Student exercise executable
add_executable(hello_world_exercises src/hello_world_exercises.cpp)

# Solution executable
add_executable(hello_world_solutions src/hello_world_solutions.cpp)

# Test executables
add_executable(test_hello_world_basics test/test_hello_world_basics.cpp)
target_link_libraries(test_hello_world_basics 
    GTest::gtest 
    GTest::gtest_main)

add_executable(test_hello_world_practice test/test_hello_world_practice.cpp)
target_link_libraries(test_hello_world_practice 
    GTest::gtest 
    GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests with labels for better organization
add_test(NAME test_basics COMMAND test_hello_world_basics)
set_property(TEST test_basics PROPERTY LABELS "basics")

add_test(NAME test_practice COMMAND test_hello_world_practice)
set_property(TEST test_practice PROPERTY LABELS "practice")

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_hello_world_basics test_hello_world_practice
    COMMENT "Running all tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_hello_world_basics
    COMMENT "Running basic tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_hello_world_practice
    COMMENT "Running practice tests with detailed output")