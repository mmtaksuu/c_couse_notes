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

add_executable(memset_fill_array src/memset_fill_array.c )
target_link_libraries(memset_fill_array ${MY_LIB})

add_executable(memset_func src/memset_func.c )
target_link_libraries(memset_func ${MY_LIB})
