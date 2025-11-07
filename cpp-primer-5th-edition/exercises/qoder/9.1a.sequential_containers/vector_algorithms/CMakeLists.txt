cmake_minimum_required(VERSION 3.10)
project(vector_algorithms)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(vector_algorithms_exercises 
    src/vector_algorithms_exercises.cpp)

# Add executable for solution
add_executable(vector_algorithms_solutions 
    src/vector_algorithms_solutions.cpp)

# Add test executables
add_executable(test_vector_algorithms_basics 
    test/test_vector_algorithms_basics.cpp)
target_link_libraries(test_vector_algorithms_basics GTest::GTest GTest::Main)

add_executable(test_vector_algorithms_practice 
    test/test_vector_algorithms_practice.cpp)
target_link_libraries(test_vector_algorithms_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(vector_algorithms_exercises PRIVATE /W4)
    target_compile_options(vector_algorithms_solutions PRIVATE /W4)
    target_compile_options(test_vector_algorithms_basics PRIVATE /W4)
    target_compile_options(test_vector_algorithms_practice PRIVATE /W4)
else()
    target_compile_options(vector_algorithms_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(vector_algorithms_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_vector_algorithms_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_vector_algorithms_practice PRIVATE -Wall -Wextra -pedantic)
endif()