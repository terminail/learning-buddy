cmake_minimum_required(VERSION 3.10)
project(function_overloading_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(function_overloading_exercises src/function_overloading_exercises.cpp)

# Add library for the solution
add_library(function_overloading_solutions src/function_overloading_solutions.cpp)

# Add executable for basic tests
add_executable(test_function_overloading_basics test/test_function_overloading_basics.cpp)
target_link_libraries(test_function_overloading_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_function_overloading_practice test/test_function_overloading_practice.cpp)
target_link_libraries(test_function_overloading_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME function_overloading_basics_test COMMAND test_function_overloading_basics)
add_test(NAME function_overloading_practice_test COMMAND test_function_overloading_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_function_overloading_basics test_function_overloading_practice
    COMMENT "Running all function overloading tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_function_overloading_basics
    COMMENT "Running basic function overloading tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_function_overloading_practice
    COMMENT "Running practice function overloading tests with detailed output")