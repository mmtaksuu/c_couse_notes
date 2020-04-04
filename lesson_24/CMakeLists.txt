cmake_minimum_required(VERSION 3.15)
project(LESSON_24 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(array_traversal src/array_traversal.c)
add_executable(reverse_array src/reverse_array.c)
add_executable(reverse_copy_array src/reverse_copy_array.c)
add_executable(compairing_address_of_arr src/compairing_address_of_arr.c)
add_executable(std_dev_mean_max_min_array src/std_dev_mean_max_min_array.c)