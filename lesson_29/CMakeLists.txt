cmake_minimum_required(VERSION 3.15)
project(LESSON_29 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(return_string src/return_string.c)


##For the static library:
set ( MY_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(define_array_size src/define_array_size.c)
target_link_libraries(define_array_size ${MY_LIB} )

add_executable(endianness_with_binary src/endianness_with_binary.c)

add_executable(endianness_with_hex src/endianness_with_hex.c)

add_executable(defining_ptr_array src/defining_ptr_array.c)
target_link_libraries(defining_ptr_array ${MY_LIB} )

add_executable(string_address_manipulation src/string_address_manipulation.c)
target_link_libraries(string_address_manipulation ${MY_LIB})

add_executable(display_rand_pnames src/display_rand_pnames.c)
target_link_libraries(display_rand_pnames ${MY_LIB})

add_executable(find_name_in_pnames src/find_name_in_pnames.c)
target_link_libraries(find_name_in_pnames ${MY_LIB})

add_executable(character_manipulations_in_pnames src/character_manipulations_in_pnames.c)
target_link_libraries(character_manipulations_in_pnames ${MY_LIB})

add_executable(string_tokenizing src/string_tokenizing.c)
target_link_libraries(string_tokenizing ${MY_LIB})

add_executable(check_is_all_characters_unique src/check_is_all_characters_unique.c)
target_link_libraries(check_is_all_characters_unique ${MY_LIB})
