cmake_minimum_required(VERSION 3.15)
project(LESSON_8 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(gets_number_with_getchar src/gets_number_with_getchar.c)
add_executable(putchar_examples src/putchar_examples.c)
add_executable(get_password src/get_password.c)
add_executable(finding_digit_values src/finding_digit_values.c)
add_executable(get_presicion_after_comma src/get_presicion_after_comma.c)
add_executable(reverse_number src/reverse_number.c)

