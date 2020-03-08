cmake_minimum_required(VERSION 3.15)
project(codility C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

add_executable(NumberOfDiscIntersections src/NumberOfDiscIntersections.c)
add_executable(CyclicRotation src/CyclicRotation.c ../../helper.c ../../helper.h)
#add_executable(bsort src/bsort.c ../../helper.c ../../helper.h)
add_executable(test src/test.c)