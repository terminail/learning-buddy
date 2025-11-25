cmake_minimum_required(VERSION 3.10)
project(virtual_functions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(virtual_functions_exercises src/virtual_functions_exercises.cpp)

# Create the solutions library
add_library(virtual_functions_solutions src/virtual_functions_solutions.cpp)

# Create the basic test executable
add_executable(test_virtual_functions_basics test/test_virtual_functions_basics.cpp)

# Create the practice test executable
add_executable(test_virtual_functions_practice test/test_virtual_functions_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_virtual_functions_basics virtual_functions_exercises)
target_link_libraries(test_virtual_functions_practice virtual_functions_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_virtual_functions_basics GTest::GTest GTest::Main)
    target_link_libraries(test_virtual_functions_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_virtual_functions_basics
    COMMAND test_virtual_functions_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all virtual functions tests"
)

add_custom_target(run_basics
    COMMAND test_virtual_functions_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic virtual functions tests"
)

add_custom_target(run_practice
    COMMAND test_virtual_functions_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice virtual functions tests"
)