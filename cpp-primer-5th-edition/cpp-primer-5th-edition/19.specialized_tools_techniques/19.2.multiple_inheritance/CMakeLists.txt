cmake_minimum_required(VERSION 3.10)
project(multiple_inheritance)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(multiple_inheritance_exercises src/multiple_inheritance_exercises.cpp)

# Create the solutions library
add_library(multiple_inheritance_solutions src/multiple_inheritance_solutions.cpp)

# Create the basic test executable
add_executable(test_multiple_inheritance_basics test/test_multiple_inheritance_basics.cpp)

# Create the practice test executable
add_executable(test_multiple_inheritance_practice test/test_multiple_inheritance_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_multiple_inheritance_basics multiple_inheritance_exercises)
target_link_libraries(test_multiple_inheritance_practice multiple_inheritance_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_multiple_inheritance_basics GTest::GTest GTest::Main)
    target_link_libraries(test_multiple_inheritance_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_multiple_inheritance_basics
    COMMAND test_multiple_inheritance_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all multiple inheritance tests"
)

add_custom_target(run_basics
    COMMAND test_multiple_inheritance_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic multiple inheritance tests"
)

add_custom_target(run_practice
    COMMAND test_multiple_inheritance_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice multiple inheritance tests"
)