cmake_minimum_required(VERSION 3.10)
project(destructor_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(destructor_basics_exercises 
    src/destructor_basics_exercises.cpp
)

# Create executable for solutions
add_executable(destructor_basics_solutions 
    src/destructor_basics_solutions.cpp
)

# Link pthread library if needed
# target_link_libraries(destructor_basics_exercises pthread)
# target_link_libraries(destructor_basics_solutions pthread)