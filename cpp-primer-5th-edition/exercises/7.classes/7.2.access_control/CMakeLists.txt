cmake_minimum_required(VERSION 3.10)
project(access_control_exercises)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add library for the exercise
add_library(access_control_exercises src/access_control_exercises.cpp)

# Add library for the solution
add_library(access_control_solutions src/access_control_solutions.cpp)

# Add executable for basic tests
add_executable(test_access_control_basics test/test_access_control_basics.cpp)
target_link_libraries(test_access_control_basics GTest::gtest GTest::gtest_main)

# Add executable for practice tests
add_executable(test_access_control_practice test/test_access_control_practice.cpp)
target_link_libraries(test_access_control_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME access_control_basics_test COMMAND test_access_control_basics)
add_test(NAME access_control_practice_test COMMAND test_access_control_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_access_control_basics test_access_control_practice
    COMMENT "Running all access control tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_access_control_basics
    COMMENT "Running basic access control tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_access_control_practice
    COMMENT "Running practice access control tests with detailed output")