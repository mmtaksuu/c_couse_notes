cmake_minimum_required(VERSION 3.15)
project(LESSON_17 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


#For the shared library:
#set ( PROJECT_LINK_LIBS libmersenne_twister.so )
#link_directories( ../libs/mersenne_twister/build )

#For the static library:
set ( PROJECT_LINK_LIBS libmersenne_twister.a )
link_directories( ../libs/mersenne_twister/build )


include_directories( ../libs/mersenne_twister/includes)

add_executable(libtest src/mt_impl_01.c)
target_link_libraries(libtest ${PROJECT_LINK_LIBS} )