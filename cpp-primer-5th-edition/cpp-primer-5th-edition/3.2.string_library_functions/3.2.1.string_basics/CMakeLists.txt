cmake_minimum_required(VERSION 3.10)
project(string_basics_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(string_basics_exercises src/string_basics_exercises.cpp)

# Add library for the solution
add_library(string_basics_solutions src/string_basics_solutions.cpp)

# Add executable for basic tests
add_executable(test_string_basics_basics test/test_string_basics_basics.cpp)
target_link_libraries(test_string_basics_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_string_basics_practice test/test_string_basics_practice.cpp)
target_link_libraries(test_string_basics_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME string_basics_basics_test COMMAND test_string_basics_basics)
add_test(NAME string_basics_practice_test COMMAND test_string_basics_practice)