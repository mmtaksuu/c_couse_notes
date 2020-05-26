cmake_minimum_required(VERSION 3.15)
project(LESSON_7 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(writes_ascii_characters src/writes_ascii_characters.c)
add_executable(prints_escape_squences src/prints_escape_squences.c)
add_executable(check_system_endianness src/check_system_endianness.c)

