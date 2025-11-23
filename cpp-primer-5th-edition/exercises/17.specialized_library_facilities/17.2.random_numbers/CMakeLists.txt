cmake_minimum_required(VERSION 3.10)
project(random_numbers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(random_numbers_exercises src/random_numbers_exercises.cpp)

# Create the solutions library
add_library(random_numbers_solutions src/random_numbers_solutions.cpp)

# Create the basic test executable
add_executable(test_random_numbers_basics test/test_random_numbers_basics.cpp)

# Create the practice test executable
add_executable(test_random_numbers_practice test/test_random_numbers_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_random_numbers_basics random_numbers_exercises)
target_link_libraries(test_random_numbers_practice random_numbers_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_random_numbers_basics GTest::GTest GTest::Main)
    target_link_libraries(test_random_numbers_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_random_numbers_basics
    COMMAND test_random_numbers_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all random numbers tests"
)

add_custom_target(run_basics
    COMMAND test_random_numbers_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic random numbers tests"
)

add_custom_target(run_practice
    COMMAND test_random_numbers_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice random numbers tests"
)