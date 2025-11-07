cmake_minimum_required(VERSION 3.10)
project(conditional_expressions)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(conditional_expressions_exercises 
    src/conditional_expressions_exercises.cpp)

# Add executable for solution
add_executable(conditional_expressions_solutions 
    src/conditional_expressions_solutions.cpp)

# Add test executables
add_executable(test_conditional_expressions_basics 
    test/test_conditional_expressions_basics.cpp)
target_link_libraries(test_conditional_expressions_basics GTest::GTest GTest::Main)

add_executable(test_conditional_expressions_practice 
    test/test_conditional_expressions_practice.cpp)
target_link_libraries(test_conditional_expressions_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(conditional_expressions_exercises PRIVATE /W4)
    target_compile_options(conditional_expressions_solutions PRIVATE /W4)
    target_compile_options(test_conditional_expressions_basics PRIVATE /W4)
    target_compile_options(test_conditional_expressions_practice PRIVATE /W4)
else()
    target_compile_options(conditional_expressions_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(conditional_expressions_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_conditional_expressions_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_conditional_expressions_practice PRIVATE -Wall -Wextra -pedantic)
endif()