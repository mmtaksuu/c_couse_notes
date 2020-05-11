cmake_minimum_required(VERSION 3.15)
project(LESSON_33 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Waddress -ansi)

#add_executable(main src/main.c)