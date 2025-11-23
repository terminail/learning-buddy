cmake_minimum_required(VERSION 3.10)
project(transformation_algorithms_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(transformation_algorithms_exercises src/transformation_algorithms_exercises.cpp)

# Add library for the solution
add_library(transformation_algorithms_solutions src/transformation_algorithms_solutions.cpp)

# Add executable for basic tests
add_executable(test_transformation_algorithms_basics test/test_transformation_algorithms_basics.cpp)
target_link_libraries(test_transformation_algorithms_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_transformation_algorithms_practice test/test_transformation_algorithms_practice.cpp)
target_link_libraries(test_transformation_algorithms_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME transformation_algorithms_basics_test COMMAND test_transformation_algorithms_basics)
add_test(NAME transformation_algorithms_practice_test COMMAND test_transformation_algorithms_practice)