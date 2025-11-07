cmake_minimum_required(VERSION 3.10)
project(variables_types_exercise)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)

# Add executable for the exercise
add_executable(variables_types_exercises 
    src/variables_types_exercises.cpp
)

# Add executable for the solution
add_executable(variables_types_solutions 
    src/variables_types_solutions.cpp
)

# Add test executable for basic tests
add_executable(test_variables_types_basics 
    test/test_variables_types_basics.cpp
)
target_link_libraries(test_variables_types_basics GTest::gtest GTest::gtest_main)

# Add test executable for practice tests
add_executable(test_variables_types_practice 
    test/test_variables_types_practice.cpp
)
target_link_libraries(test_variables_types_practice GTest::gtest GTest::gtest_main)

# Enable testing
enable_testing()

# Add tests
add_test(NAME variables_types_basics_test COMMAND test_variables_types_basics)
add_test(NAME variables_types_practice_test COMMAND test_variables_types_practice)

# Custom target for running all tests
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_variables_types_basics test_variables_types_practice
    COMMENT "Running all tests with detailed output")

# Custom target for running basic tests only
add_custom_target(run_basics
    COMMAND ${CMAKE_CTEST_COMMAND} -L basics --output-on-failure
    DEPENDS test_variables_types_basics
    COMMENT "Running basic tests with detailed output")

# Custom target for running practice tests only
add_custom_target(run_practice
    COMMAND ${CMAKE_CTEST_COMMAND} -L practice --output-on-failure
    DEPENDS test_variables_types_practice
    COMMENT "Running practice tests with detailed output")

# Customization Instructions:
# 1. Update project name: project(your_exercise_name)
# 2. Update library names: exercise_name_exercises → your_exercise_exercises
# 3. Update executable names: test_exercise_name_basics → test_your_exercise_basics
# 4. Update target link libraries accordingly
#
# Example customization for string_basics exercise:
# project(string_basics)
# add_library(string_basics_exercises src/string_basics_exercises.cpp)
# add_library(string_basics_solutions src/string_basics_solutions.cpp)
# add_executable(test_string_basics_basics test/test_string_basics_basics.cpp)
# add_executable(test_string_basics_practice test/test_string_basics_practice.cpp)