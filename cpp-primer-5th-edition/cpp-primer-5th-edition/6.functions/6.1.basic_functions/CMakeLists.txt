cmake_minimum_required(VERSION 3.10)
project(basic_functions)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(basic_functions_exercises 
    src/basic_functions_exercises.cpp)

# Add executable for solution
add_executable(basic_functions_solutions 
    src/basic_functions_solutions.cpp)

# Add test executables
add_executable(test_basic_functions_basics 
    test/test_basic_functions_basics.cpp)
target_link_libraries(test_basic_functions_basics GTest::GTest GTest::Main)

add_executable(test_basic_functions_practice 
    test/test_basic_functions_practice.cpp)
target_link_libraries(test_basic_functions_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(basic_functions_exercises PRIVATE /W4)
    target_compile_options(basic_functions_solutions PRIVATE /W4)
    target_compile_options(test_basic_functions_basics PRIVATE /W4)
    target_compile_options(test_basic_functions_practice PRIVATE /W4)
else()
    target_compile_options(basic_functions_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(basic_functions_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_basic_functions_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_basic_functions_practice PRIVATE -Wall -Wextra -pedantic)
endif()