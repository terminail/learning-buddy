cmake_minimum_required(VERSION 3.10)
project(function_templates)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(function_templates_exercises src/function_templates_exercises.cpp)

# Create the solutions library
add_library(function_templates_solutions src/function_templates_solutions.cpp)

# Create the basic test executable
add_executable(test_function_templates_basics test/test_function_templates_basics.cpp)

# Create the practice test executable
add_executable(test_function_templates_practice test/test_function_templates_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_function_templates_basics function_templates_exercises)
target_link_libraries(test_function_templates_practice function_templates_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_function_templates_basics GTest::GTest GTest::Main)
    target_link_libraries(test_function_templates_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_function_templates_basics
    COMMAND test_function_templates_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all function templates tests"
)

add_custom_target(run_basics
    COMMAND test_function_templates_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic function templates tests"
)

add_custom_target(run_practice
    COMMAND test_function_templates_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice function templates tests"
)