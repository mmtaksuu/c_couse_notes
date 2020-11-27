cmake_minimum_required(VERSION 3.15)
project(LESSON_35)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


add_executable(generate_log_file_name src/generate_log_file_name.c)
add_executable(urand_impl src/urand_impl.c)
add_executable(strtok_usage src/strtok_usage.c)


