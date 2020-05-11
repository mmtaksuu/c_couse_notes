cmake_minimum_required(VERSION 3.15)
project(LESSON_31 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

##For the static library:
set ( MY_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(fill_array_w_memset src/fill_array_w_memset.c)
target_link_libraries(fill_array_w_memset ${MY_LIB})

add_executable(my_memset_func src/my_memset_func.c)
target_link_libraries(my_memset_func ${MY_LIB})

add_executable(working_of_memset src/working_of_memset.c)
target_link_libraries(working_of_memset ${MY_LIB})

add_executable(memcpy_exp_1 src/memcpy_exp_1.c)
target_link_libraries(memcpy_exp_1 ${MY_LIB})

add_executable(memcpy_exp_w_malloc src/memcpy_exp_w_malloc.c)
target_link_libraries(memcpy_exp_w_malloc ${MY_LIB})

add_executable(my_memcpy_func src/my_memcpy_func.c)
target_link_libraries(my_memcpy_func ${MY_LIB})

add_executable(memcpy_w_strings src/memcpy_w_strings.c)
target_link_libraries(memcpy_w_strings ${MY_LIB})

add_executable(memmove_exp src/memmove_exp.c)

add_executable(memmove_str_prepend_exp src/memmove_str_prepend_exp.c)

add_executable(memchr_exp src/memchr_exp.c)
target_link_libraries(memchr_exp ${MY_LIB})

add_executable(my_strtok_func src/my_strtok_func.c)
target_link_libraries(my_strtok_func ${MY_LIB})

add_executable(strtok_with_files src/strtok_with_files.c)
target_link_libraries(strtok_with_files ${MY_LIB})
