cmake_minimum_required(VERSION 3.10)
project(exception_handling)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(exception_handling_exercises src/exception_handling_exercises.cpp)

# Create the solutions library
add_library(exception_handling_solutions src/exception_handling_solutions.cpp)

# Create the basic test executable
add_executable(test_exception_handling_basics test/test_exception_handling_basics.cpp)

# Create the practice test executable
add_executable(test_exception_handling_practice test/test_exception_handling_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_exception_handling_basics exception_handling_exercises)
target_link_libraries(test_exception_handling_practice exception_handling_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_exception_handling_basics GTest::GTest GTest::Main)
    target_link_libraries(test_exception_handling_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_exception_handling_basics
    COMMAND test_exception_handling_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all exception handling tests"
)

add_custom_target(run_basics
    COMMAND test_exception_handling_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic exception handling tests"
)

add_custom_target(run_practice
    COMMAND test_exception_handling_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice exception handling tests"
)