cmake_minimum_required(VERSION 3.15)
project(lesson_16.md C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(main src/main.c)