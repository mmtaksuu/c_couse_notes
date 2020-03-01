cmake_minimum_required(VERSION 3.15)
project(LESSON_31 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(memset_fill_array src/memset_fill_array.c ../../helper.c ../../helper.h)
add_executable(memset_func src/memset_func.c ../../helper.c ../../helper.h)