cmake_minimum_required(VERSION 3.15)
project(LESSON_20 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


add_executable(buble_short_1 src/buble_short_1.c ../../helper.c ../../helper.h)
add_executable(bubble_sort_2 src/bubble_sort_2.c ../../helper.c ../../helper.h)
add_executable(step_by_step_bubble_sort_implement src/step_by_step_bubble_sort_implement.c)
add_executable(array_name_and_iter_variable_usage src/array_name_and_iter_variable_usage.c)
add_executable(qsort_implementation src/qsort_implementation.c)
add_executable(merge_algorithm src/merge_algorithm.c)
add_executable(binary_search src/binary_search.c)
add_executable(find_mod_value_of_arrays src/find_mod_value_of_arrays.c)
add_executable(strings_1 src/strings_1.c)
add_executable(sizeof_strings src/sizeof_strings.c)
add_executable(generating_random_numbers src/generating_random_numbers.c)