cmake_minimum_required(VERSION 3.14)
project(pair_basics_exercise)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GoogleTest
find_package(GTest REQUIRED)

# Create executable for exercises
add_executable(pair_basics_exercises 
    src/pair_basics_exercises.cpp
)

# Create executable for solutions
add_executable(pair_basics_solutions 
    src/pair_basics_solutions.cpp
)

# Create test executable for basics
add_executable(test_pair_basics_basics 
    test/test_pair_basics_basics.cpp
)

# Create test executable for practice
add_executable(test_pair_basics_practice 
    test/test_pair_basics_practice.cpp
)

# Link GoogleTest to test executables
target_link_libraries(test_pair_basics_basics 
    GTest::gtest_main
)

target_link_libraries(test_pair_basics_practice 
    GTest::gtest_main
)

# Enable testing
enable_testing()

# Add tests
add_test(NAME pair_basics_test 
         COMMAND test_pair_basics_basics)

add_test(NAME pair_practice_test 
         COMMAND test_pair_basics_practice)