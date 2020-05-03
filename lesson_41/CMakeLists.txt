cmake_minimum_required(VERSION 3.15)
project(LESSON_41 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(babil_algorithm src/babil_algorithm.c)
add_executable(randomize src/randomize.c)
add_executable(path_splitting src/path_splitting.c)
add_executable(find_dist_on_the_earth src/find_dist_on_the_earth.c)


