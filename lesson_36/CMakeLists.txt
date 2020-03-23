cmake_minimum_required(VERSION 3.15)
project(LESSON_36 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(main src/test_main.c src/test.c src/test.h)

add_executable(structs_and_funcs_1 src/structs_and_funcs_1.c)
add_executable(complex_numbers src/complex_numbers.c)