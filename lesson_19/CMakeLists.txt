cmake_minimum_required(VERSION 3.15)
project(LESSON_19 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


#For the static library:
set ( UTILS_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(linear_searching_imp src/linear_searching_imp.c)
target_link_libraries(linear_searching_imp ${UTILS_LIB})

add_executable(ders19 src/ders19.c)
target_link_libraries(ders19 ${UTILS_LIB})
