cmake_minimum_required(VERSION 3.10)
project(namespaces)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(namespaces_exercises src/namespaces_exercises.cpp)

# Create the solutions library
add_library(namespaces_solutions src/namespaces_solutions.cpp)

# Create the basic test executable
add_executable(test_namespaces_basics test/test_namespaces_basics.cpp)

# Create the practice test executable
add_executable(test_namespaces_practice test/test_namespaces_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_namespaces_basics namespaces_exercises)
target_link_libraries(test_namespaces_practice namespaces_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_namespaces_basics GTest::GTest GTest::Main)
    target_link_libraries(test_namespaces_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_namespaces_basics
    COMMAND test_namespaces_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all namespaces tests"
)

add_custom_target(run_basics
    COMMAND test_namespaces_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic namespaces tests"
)

add_custom_target(run_practice
    COMMAND test_namespaces_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice namespaces tests"
)