cmake_minimum_required(VERSION 3.15)
project(LESSON_26 C)

set(CMAKE_C_STANDARD 11)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(search src/search.c)