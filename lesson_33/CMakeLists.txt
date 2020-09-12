cmake_minimum_required(VERSION 3.15)
project(LESSON_33 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Waddress -ansi)

add_executable(normal_termination  src/normal_termination.c)
add_executable(normal_termination_exit src/normal_termination_exit.c)
add_executable(atexit_termination src/atexit_termination.c)
add_executable(assert_macro src/assert_macro.c)