cmake_minimum_required(VERSION 3.15)
project(LESSON_30 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

##For the static library:
set ( MY_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(atof_example src/strtok_with_atof.c)
target_link_libraries(atof_example ${MY_LIB} )

add_executable(converts_int_to_string src/converts_int_to_string.c)

add_executable(recursive_int_to_string src/recursive_int_to_string.c)

add_executable(indicate_as_bin_hex_dec src/indicate_as_bin_hex_dec.c)

add_executable(pointer_to_pointer_1 src/pointer_to_pointer_1.c)

add_executable(pointer_to_pointer_2 src/pointer_to_pointer_2.c)
target_link_libraries(pointer_to_pointer_2 ${MY_LIB} )

add_executable(pointer_swap src/pointer_swap.c)

add_executable(string_to_double src/string_to_double.c)

add_executable(sort_strings src/sort_strings.c)
target_link_libraries(sort_strings ${MY_LIB} )

add_executable(string_manipulation src/string_manipulation.c)
