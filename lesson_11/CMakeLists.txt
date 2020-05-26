cmake_minimum_required(VERSION 3.15)
project(LESSON_11 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(prime_numbers_finder src/prime_numbers_finder.c)
add_executable(perfect_number_finder src/perfect_number_finder.c)
add_executable(delay_operation src/delay_operation.c)
add_executable(ctype_exp src/ctype_exp.c)
add_executable(get_hex_and_decimal_input src/get_hex_and_decimal_input.c)
