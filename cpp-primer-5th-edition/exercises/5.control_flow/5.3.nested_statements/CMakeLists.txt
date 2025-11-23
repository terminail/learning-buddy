cmake_minimum_required(VERSION 3.10)
project(nested_statements)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(nested_statements_exercises 
    src/nested_statements_exercises.cpp)

# Add executable for solution
add_executable(nested_statements_solutions 
    src/nested_statements_solutions.cpp)

# Add test executables
add_executable(test_nested_statements_basics 
    test/test_nested_statements_basics.cpp)
target_link_libraries(test_nested_statements_basics GTest::GTest GTest::Main)

add_executable(test_nested_statements_practice 
    test/test_nested_statements_practice.cpp)
target_link_libraries(test_nested_statements_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(nested_statements_exercises PRIVATE /W4)
    target_compile_options(nested_statements_solutions PRIVATE /W4)
    target_compile_options(test_nested_statements_basics PRIVATE /W4)
    target_compile_options(test_nested_statements_practice PRIVATE /W4)
else()
    target_compile_options(nested_statements_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(nested_statements_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_nested_statements_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_nested_statements_practice PRIVATE -Wall -Wextra -pedantic)
endif()