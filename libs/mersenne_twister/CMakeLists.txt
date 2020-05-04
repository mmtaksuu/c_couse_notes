cmake_minimum_required(VERSION 3.15)
project(Mersenne_Twister_Lib C)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

#Bring the headers, such as Student.h into the project
include_directories(includes)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

option(MT_Lib "Build static library" ON)

if(MT_Lib)
    add_library(mersenne_twister STATIC ${SOURCES}) # STATIC
else()
    add_library(mersenne_twister SHARED ${SOURCES}) # SHARED
endif()


#Install the library to the given directory
install(TARGETS mersenne_twister
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)