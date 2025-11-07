cmake_minimum_required(VERSION 3.10)
project(variables_declarations)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(variables_declarations_exercises 
    src/variables_declarations_exercises.cpp
    src/variables_declarations_exercises_class.cpp)

# Add executable for solution
add_executable(variables_declarations_solutions 
    src/variables_declarations_solutions.cpp
    src/variables_declarations_solutions_class.cpp)

# Add test executables
add_executable(test_variables_declarations_basics 
    test/test_variables_declarations_basics.cpp)
target_link_libraries(test_variables_declarations_basics GTest::GTest GTest::Main)

add_executable(test_variables_declarations_practice 
    test/test_variables_declarations_practice.cpp)
target_link_libraries(test_variables_declarations_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(variables_declarations_exercises PRIVATE /W4)
    target_compile_options(variables_declarations_solutions PRIVATE /W4)
    target_compile_options(test_variables_declarations_basics PRIVATE /W4)
    target_compile_options(test_variables_declarations_practice PRIVATE /W4)
else()
    target_compile_options(variables_declarations_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(variables_declarations_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_variables_declarations_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_variables_declarations_practice PRIVATE -Wall -Wextra -pedantic)
endif()