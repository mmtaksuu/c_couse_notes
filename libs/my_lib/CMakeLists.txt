cmake_minimum_required(VERSION 3.15)
project(MY_LIB C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


#Bring the headers, such as Student.h into the project
include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c" "include/*.h")

#Generate the shared library from the sources
add_library(my_lib STATIC ${SOURCES}) # STATIC or SHARED

#Install the library to the given directory
install(TARGETS my_lib DESTINATION build)

