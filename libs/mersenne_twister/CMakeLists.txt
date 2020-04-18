cmake_minimum_required(VERSION 3.15)
project(Mersenne_Twister_Lib C)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#Bring the headers, such as Student.h into the project
include_directories(includes)

#Can manually add the sources using the set command as follows:
set(SOURCES src/mersenne_twister.c)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

#Generate the shared library from the sources
add_library(mersenne_twister STATIC ${SOURCES}) # STATIC or SHARED

#Install the library to the given directory
install(TARGETS mersenne_twister DESTINATION build)