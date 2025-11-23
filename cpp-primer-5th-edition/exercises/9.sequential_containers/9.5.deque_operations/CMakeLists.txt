cmake_minimum_required(VERSION 3.10)
project(deque_operations_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(deque_operations_exercises src/deque_operations_exercises.cpp)

# Add library for the solution
add_library(deque_operations_solutions src/deque_operations_solutions.cpp)

# Add executable for basic tests
add_executable(test_deque_operations_basics test/test_deque_operations_basics.cpp)
target_link_libraries(test_deque_operations_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_deque_operations_practice test/test_deque_operations_practice.cpp)
target_link_libraries(test_deque_operations_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME deque_operations_basics_test COMMAND test_deque_operations_basics)
add_test(NAME deque_operations_practice_test COMMAND test_deque_operations_practice)