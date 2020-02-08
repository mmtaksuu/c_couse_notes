cmake_minimum_required(VERSION 3.15)
project(LESSON_13 C)

set(CMAKE_C_STANDARD 99)
#set (CMAKE_CXX_STANDARD 14)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(for_loop1 src/for_loop1.c )
add_executable(for_loop2 src/for_loop2.c)
add_executable(recursive_01 src/recursive_01.c)
add_executable(factorial src/factorial.c)
add_executable(factorial_look_up_table src/factorial_look_up_table.c)
add_executable(recursive_factroial src/recursive_factroial.c)
add_executable(fibonacci src/fibonacci.c)
add_executable(perfect_numbers_with_loops src/perfect_numbers_with_loops.c)
add_executable(unique_numbers src/unique_numbers.c)
add_executable(find_multipliers src/find_multipliers.c)
