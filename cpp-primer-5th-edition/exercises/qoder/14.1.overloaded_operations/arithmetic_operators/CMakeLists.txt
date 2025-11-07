cmake_minimum_required(VERSION 3.10)
project(arithmetic_operators)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(arithmetic_operators_exercises 
    src/arithmetic_operators_exercises.cpp
)

# Create executable for solutions
add_executable(arithmetic_operators_solutions 
    src/arithmetic_operators_solutions.cpp
)

# Link pthread library if needed
# target_link_libraries(arithmetic_operators_exercises pthread)
# target_link_libraries(arithmetic_operators_solutions pthread)