cmake_minimum_required(VERSION 3.15)
project(LESSON_40 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(random_set_reset_bits src/random_set_reset_bits.c)
add_executable(print_bits_func src/print_bits_func.c)
add_executable(print_hex_bits src/print_hex_bits.c)
add_executable(random_set_reset_2 src/random_set_reset_2.c)
add_executable(check_given_number src/check_given_number.c)
add_executable(prints_bits_2 src/prints_bits_2.c)
add_executable(uretim_kritik_01 src/uretim_kritik_01.c)
add_executable(uretim_kritik_02 src/uretim_kritik_02.c)
add_executable(uretim_kritik_03 src/uretim_kritik_03.c)
add_executable(uretim_kritik_04 src/uretim_kritik_04.c)
add_executable(uretim_kritik_05 src/uretim_kritik_05.c)
add_executable(uretim_kritik_06 src/uretim_kritik_06.c)