cmake_minimum_required(VERSION 3.15)
project(LESSON_17 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

option(MT_Lib "Build static library" ON)

if(MT_Lib)
    set ( MERSENNE_LIBS libmersenne_twister.a ) # STATIC
else()
    set ( MERSENNE_LIBS libmersenne_twister.dll ) # SHARED
endif()


set( LIBRARY_BUILD_DIR ../libs/mersenne_twister/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/mersenne_twister/includes)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(libtest src/mt_impl_01.c)
target_link_libraries(libtest PUBLIC ${MERSENNE_LIBS})
