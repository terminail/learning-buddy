cmake_minimum_required(VERSION 3.10)
project(bitset_operations)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(bitset_operations_exercises src/bitset_operations_exercises.cpp)

# Create the solutions library
add_library(bitset_operations_solutions src/bitset_operations_solutions.cpp)

# Create the basic test executable
add_executable(test_bitset_operations_basics test/test_bitset_operations_basics.cpp)

# Create the practice test executable
add_executable(test_bitset_operations_practice test/test_bitset_operations_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_bitset_operations_basics bitset_operations_exercises)
target_link_libraries(test_bitset_operations_practice bitset_operations_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_bitset_operations_basics GTest::GTest GTest::Main)
    target_link_libraries(test_bitset_operations_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_bitset_operations_basics
    COMMAND test_bitset_operations_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all bitset operations tests"
)

add_custom_target(run_basics
    COMMAND test_bitset_operations_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic bitset operations tests"
)

add_custom_target(run_practice
    COMMAND test_bitset_operations_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice bitset operations tests"
)