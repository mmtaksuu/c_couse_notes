cmake_minimum_required(VERSION 3.15)
project(LESSON_34 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(get_allocated_memory src/get_allocated_memory.c)
add_executable(strdup_imp src/strdup_imp.c)
add_executable(string_concatenate src/string_concatenate.c)
add_executable(generate_random_password src/generate_random_password.c)
add_executable(get_rand_2d_matrix src/generate_rand_2d_matrix.c)
add_executable(generate_rand_2d_solid_array src/generate_rand_2d_solid_array.c)
add_executable(generate_rand_2d_hibrit_matrix src/generate_rand_2d_hibrit_matrix.c)
add_executable(realloc_func_usage src/realloc_func_usage.c)