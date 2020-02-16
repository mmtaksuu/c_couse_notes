cmake_minimum_required(VERSION 3.15)
project(LESSON_27 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(strlen_function src/strlen_function.c)
add_executable(puts_function src/puts_function.c)
add_executable(rputs_function src/rputs_function.c)
add_executable(strchr_function src/strchr_function.c)
add_executable(rstrchr_function src/rstrchr_function.c)
add_executable(strcpy_function src/strcpy_function.c)
add_executable(strcat_function src/strcat_function.c)
add_executable(strstr_function src/strstr_function.c)