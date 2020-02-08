cmake_minimum_required(VERSION 3.15)
project(LESSON_15 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Waddress  -ansi)

add_executable(function_like_macros_01 src/function_like_macros_01.c)
add_executable(func_like_macros_02 src/func_like_macros_02.c)