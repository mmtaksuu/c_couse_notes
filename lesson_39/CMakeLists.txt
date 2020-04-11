cmake_minimum_required(VERSION 3.15)
project(LESSON_39 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -Werror -Wconversion -Wsign-conversion -fdiagnostics-show-option) # -pedantic-errors

add_executable(bitwise_not src/bitwise_not.c)
add_executable(bitwise_shift_1 src/bitwise_shift_1.c)
