cmake_minimum_required(VERSION 3.10)
project(basic_sorting_algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(basic_sorting_algorithms_exercises src/basic_sorting_algorithms_exercises.cpp)

# Create the solutions library
add_library(basic_sorting_algorithms_solutions src/basic_sorting_algorithms_solutions.cpp)

# Add executable versions of the solutions
add_executable(basic_sorting_algorithms_solutions_exe src/basic_sorting_algorithms_solutions.cpp)

# Create the basic test executable
add_executable(test_basic_sorting_algorithms_basics test/test_basic_sorting_algorithms_basics.cpp)

# Create the practice test executable
add_executable(test_basic_sorting_algorithms_practice test/test_basic_sorting_algorithms_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_basic_sorting_algorithms_basics basic_sorting_algorithms_exercises)
target_link_libraries(test_basic_sorting_algorithms_practice basic_sorting_algorithms_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_basic_sorting_algorithms_basics GTest::GTest GTest::Main)
    target_link_libraries(test_basic_sorting_algorithms_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_basic_sorting_algorithms_basics
    COMMAND test_basic_sorting_algorithms_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all basic sorting algorithms tests"
)

add_custom_target(run_basics
    COMMAND test_basic_sorting_algorithms_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic sorting algorithms tests"
)

add_custom_target(run_practice
    COMMAND test_basic_sorting_algorithms_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice basic sorting algorithms tests"
)