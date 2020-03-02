cmake_minimum_required(VERSION 3.15)
project(LESSON_32 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Waddress -ansi)

add_executable(function_address_pointer src/function_address_pointer.c)
add_executable(qsort_impl_01 src/qsort_impl_01.c ../../helper.c ../../helper.h)