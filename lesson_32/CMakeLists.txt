cmake_minimum_required(VERSION 3.15)
project(LESSON_32 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion -Waddress -ansi)

add_executable(function_address_pointer src/function_address_pointer.c)


##For the static library:
set ( MY_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(qsort_impl_01 src/qsort_impl_01.c)
target_link_libraries(qsort_impl_01 ${MY_LIB} )

add_executable(generic_sort_01 src/generic_sort_01.c)
target_link_libraries(generic_sort_01 ${MY_LIB} )

#add_executable(generic_sort_02 src/generic_sort_02.c)
