cmake_minimum_required(VERSION 3.15)
project(LESSON_6 C CXX)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(power_func src/power_func.c)
add_executable(type_id_func src/type_id_func.cpp)

