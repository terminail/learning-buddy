cmake_minimum_required(VERSION 3.10)
project(file_streams)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(file_streams_exercises src/file_streams_exercises.cpp)

# Create the solutions library
add_library(file_streams_solutions src/file_streams_solutions.cpp)

# Create the basic test executable
add_executable(test_file_streams_basics test/test_file_streams_basics.cpp)

# Create the practice test executable
add_executable(test_file_streams_practice test/test_file_streams_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_file_streams_basics file_streams_exercises)
target_link_libraries(test_file_streams_practice file_streams_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_file_streams_basics GTest::GTest GTest::Main)
    target_link_libraries(test_file_streams_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_file_streams_basics
    COMMAND test_file_streams_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all file streams tests"
)

add_custom_target(run_basics
    COMMAND test_file_streams_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic file streams tests"
)

add_custom_target(run_practice
    COMMAND test_file_streams_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice file streams tests"
)