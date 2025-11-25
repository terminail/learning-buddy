cmake_minimum_required(VERSION 3.10)
project(dynamic_allocation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(dynamic_allocation_exercises src/dynamic_allocation_exercises.cpp)

# Create the solutions library
add_library(dynamic_allocation_solutions src/dynamic_allocation_solutions.cpp)

# Create the basic test executable
add_executable(test_dynamic_allocation_basics test/test_dynamic_allocation_basics.cpp)

# Create the practice test executable
add_executable(test_dynamic_allocation_practice test/test_dynamic_allocation_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_dynamic_allocation_basics dynamic_allocation_exercises)
target_link_libraries(test_dynamic_allocation_practice dynamic_allocation_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_dynamic_allocation_basics GTest::GTest GTest::Main)
    target_link_libraries(test_dynamic_allocation_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_dynamic_allocation_basics
    COMMAND test_dynamic_allocation_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all dynamic allocation tests"
)

add_custom_target(run_basics
    COMMAND test_dynamic_allocation_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic dynamic allocation tests"
)

add_custom_target(run_practice
    COMMAND test_dynamic_allocation_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice dynamic allocation tests"
)