cmake_minimum_required(VERSION 3.15)
project(THREADS C)

set(CMAKE_C_STANDARD 11)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)

add_executable(thread_01 src/thread_01.c)

#find_package(Threads REQUIRED)

target_link_libraries(thread_01 ${CMAKE_THREAD_LIBS_INIT})