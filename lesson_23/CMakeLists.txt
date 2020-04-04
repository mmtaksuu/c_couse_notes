cmake_minimum_required(VERSION 3.15)
project(LESSON_23 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(static_keyword src/static_keyword.c)
add_executable(const_semantics src/const_semantics.c)
add_executable(ptr_aritmetics src/ptr_aritmetics.c)
