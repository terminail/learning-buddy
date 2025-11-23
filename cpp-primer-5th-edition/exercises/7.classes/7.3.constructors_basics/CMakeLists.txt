cmake_minimum_required(VERSION 3.10)
project(constructors_basics_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(constructors_basics_exercises src/constructors_basics_exercises.cpp)

# Add library for the solution
add_library(constructors_basics_solutions src/constructors_basics_solutions.cpp)

# Add executable for basic tests
add_executable(test_constructors_basics test/test_constructors_basics.cpp)
target_link_libraries(test_constructors_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_constructors_practice test/test_constructors_practice.cpp)
target_link_libraries(test_constructors_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME constructors_basics_test COMMAND test_constructors_basics)
add_test(NAME constructors_practice_test COMMAND test_constructors_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_constructors_basics test_constructors_practice
    COMMENT "Running all constructors basics tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_constructors_basics
    COMMENT "Running basic constructors basics tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_constructors_practice
    COMMENT "Running practice constructors basics tests with detailed output")