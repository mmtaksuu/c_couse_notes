cmake_minimum_required(VERSION 3.15)
project(LESSON_36 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(print_second src/print_second.c)
add_executable(display_current_time src/display_current_time.c)
add_executable(get_passed_time src/get_passed_time.c)
add_executable(thread_exp src/thread_exp.c)
