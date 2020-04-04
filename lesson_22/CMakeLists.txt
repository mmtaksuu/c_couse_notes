cmake_minimum_required(VERSION 3.15)
project(LESSON_22 C CXX)

#set(CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


add_executable(type_id src/typed_id_.cpp)
add_executable(call_by_val src/call_by_val.c)
add_executable(call_by_ref src/call_by_ref.c)