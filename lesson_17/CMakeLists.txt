cmake_minimum_required(VERSION 3.15)
project(LESSON_17 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


#For the shared library:
#set ( MERSENNE_LIBS libmersenne_twister.dll )  # .dll or .so

#For the static library:
set ( MERSENNE_LIBS libmersenne_twister.a )

set( LIBRARY_BUILD_DIR ../libs/mersenne_twister/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/mersenne_twister/includes)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(libtest src/mt_impl_01.c)
target_link_libraries(libtest ${MERSENNE_LIBS} )
