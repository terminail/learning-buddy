cmake_minimum_required(VERSION 3.10)
project(map_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(map_basics_exercises 
    src/map_basics_exercises.cpp
)

# Create executable for solutions
add_executable(map_basics_solutions 
    src/map_basics_solutions.cpp
)

# Link pthread library if needed
# target_link_libraries(map_basics_exercises pthread)
# target_link_libraries(map_basics_solutions pthread)