cmake_minimum_required(VERSION 3.10)
project(array_manipulation_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(array_manipulation_exercises src/array_manipulation_exercises.cpp)

# Add library for the solution
add_library(array_manipulation_solutions src/array_manipulation_solutions.cpp)

# Add executable for basic tests
add_executable(test_array_manipulation_basics test/test_array_manipulation_basics.cpp)
target_link_libraries(test_array_manipulation_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_array_manipulation_practice test/test_array_manipulation_practice.cpp)
target_link_libraries(test_array_manipulation_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME array_manipulation_basics_test COMMAND test_array_manipulation_basics)
add_test(NAME array_manipulation_practice_test COMMAND test_array_manipulation_practice)