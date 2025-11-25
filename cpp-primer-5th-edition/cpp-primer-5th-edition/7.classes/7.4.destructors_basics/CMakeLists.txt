cmake_minimum_required(VERSION 3.10)
project(destructors_basics_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(destructors_basics_exercises src/destructors_basics_exercises.cpp)

# Add library for the solution
add_library(destructors_basics_solutions src/destructors_basics_solutions.cpp)

# Add executable for basic tests
add_executable(test_destructors_basics test/test_destructors_basics.cpp)
target_link_libraries(test_destructors_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_destructors_practice test/test_destructors_practice.cpp)
target_link_libraries(test_destructors_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME destructors_basics_test COMMAND test_destructors_basics)
add_test(NAME destructors_practice_test COMMAND test_destructors_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_destructors_basics test_destructors_practice
    COMMENT "Running all destructors basics tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_destructors_basics
    COMMENT "Running basic destructors basics tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_destructors_practice
    COMMENT "Running practice destructors basics tests with detailed output")