cmake_minimum_required(VERSION 3.10)
project(inheritance_basics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(inheritance_basics_exercises src/inheritance_basics_exercises.cpp)

# Create the solutions library
add_library(inheritance_basics_solutions src/inheritance_basics_solutions.cpp)

# Create the basic test executable
add_executable(test_inheritance_basics_basics test/test_inheritance_basics_basics.cpp)

# Create the practice test executable
add_executable(test_inheritance_basics_practice test/test_inheritance_basics_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_inheritance_basics_basics inheritance_basics_exercises)
target_link_libraries(test_inheritance_basics_practice inheritance_basics_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_inheritance_basics_basics GTest::GTest GTest::Main)
    target_link_libraries(test_inheritance_basics_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_inheritance_basics_basics
    COMMAND test_inheritance_basics_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all inheritance basics tests"
)

add_custom_target(run_basics
    COMMAND test_inheritance_basics_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic inheritance basics tests"
)

add_custom_target(run_practice
    COMMAND test_inheritance_basics_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice inheritance basics tests"
)