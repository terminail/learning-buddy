cmake_minimum_required(VERSION 3.14)
project(container_adapters_exercise)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GoogleTest
find_package(GTest REQUIRED)

# Create executable for exercises
add_executable(container_adapters_exercises 
    src/container_adapters_exercises.cpp
)

# Create executable for solutions
add_executable(container_adapters_solutions 
    src/container_adapters_solutions.cpp
)

# Create test executable for basics
add_executable(test_container_adapters_basics 
    test/test_container_adapters_basics.cpp
)

# Create test executable for practice
add_executable(test_container_adapters_practice 
    test/test_container_adapters_practice.cpp
)

# Link GoogleTest to test executables
target_link_libraries(test_container_adapters_basics 
    GTest::gtest_main
)

target_link_libraries(test_container_adapters_practice 
    GTest::gtest_main
)

# Enable testing
enable_testing()

# Add tests
add_test(NAME container_adapters_basics_test 
         COMMAND test_container_adapters_basics)

add_test(NAME container_adapters_practice_test 
         COMMAND test_container_adapters_practice)