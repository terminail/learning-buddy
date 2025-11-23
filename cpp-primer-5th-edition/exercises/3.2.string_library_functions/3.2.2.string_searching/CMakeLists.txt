cmake_minimum_required(VERSION 3.10)
project(string_searching_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(string_searching_exercises src/string_searching_exercises.cpp)

# Add library for the solution
add_library(string_searching_solutions src/string_searching_solutions.cpp)

# Add executable for basic tests
add_executable(test_string_searching_basics test/test_string_searching_basics.cpp)
target_link_libraries(test_string_searching_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_string_searching_practice test/test_string_searching_practice.cpp)
target_link_libraries(test_string_searching_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME string_searching_basics_test COMMAND test_string_searching_basics)
add_test(NAME string_searching_practice_test COMMAND test_string_searching_practice)