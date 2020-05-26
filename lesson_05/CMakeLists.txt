cmake_minimum_required(VERSION 3.15)
project(LESSON_5 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(get_num_and_sum_of_digits src/get_num_and_sum_of_digits.c)

