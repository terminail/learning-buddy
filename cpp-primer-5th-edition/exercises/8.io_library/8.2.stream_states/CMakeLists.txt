cmake_minimum_required(VERSION 3.10)
project(stream_states)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(stream_states_exercises src/stream_states_exercises.cpp)

# Create the solutions library
add_library(stream_states_solutions src/stream_states_solutions.cpp)

# Create the basic test executable
add_executable(test_stream_states_basics test/test_stream_states_basics.cpp)

# Create the practice test executable
add_executable(test_stream_states_practice test/test_stream_states_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_stream_states_basics stream_states_exercises)
target_link_libraries(test_stream_states_practice stream_states_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_stream_states_basics GTest::GTest GTest::Main)
    target_link_libraries(test_stream_states_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_stream_states_basics
    COMMAND test_stream_states_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all stream states tests"
)

add_custom_target(run_basics
    COMMAND test_stream_states_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic stream states tests"
)

add_custom_target(run_practice
    COMMAND test_stream_states_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice stream states tests"
)