cmake_minimum_required(VERSION 3.15)
project(LESSON_10 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(quadratic_equation_solver src/quadratic_equation_solver.c)
add_executable(armstrong_numbers_finder src/armstrong_numbers_finder.c)

