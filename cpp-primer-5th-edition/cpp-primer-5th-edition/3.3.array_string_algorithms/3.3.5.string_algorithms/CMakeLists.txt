cmake_minimum_required(VERSION 3.10)
project(string_algorithms_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(string_algorithms_exercises src/string_algorithms_exercises.cpp)

# Add library for the solution
add_library(string_algorithms_solutions src/string_algorithms_solutions.cpp)

# Add executable for basic tests
add_executable(test_string_algorithms_basics test/test_string_algorithms_basics.cpp)
target_link_libraries(test_string_algorithms_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_string_algorithms_practice test/test_string_algorithms_practice.cpp)
target_link_libraries(test_string_algorithms_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME string_algorithms_basics_test COMMAND test_string_algorithms_basics)
add_test(NAME string_algorithms_practice_test COMMAND test_string_algorithms_practice)