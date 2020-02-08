cmake_minimum_required(VERSION 3.15)
project(LESSON_21 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(reverse_text src/reverse_text.c)
add_executable(reverse_with_swap src/reverse_with_swap.c)
add_executable(is_text_polindrom src/is_text_polindrom.c)
add_executable(count_characters_in_text src/count_characters_in_text.c)
add_executable(counts_all_character_numbers_in_text src/counts_all_character_numbers_in_text.c)
