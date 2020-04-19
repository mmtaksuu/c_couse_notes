cmake_minimum_required(VERSION 3.15)
project(LESSON_41 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#For the shared library:
set ( CURL_LIBS  C:/MinGW/CURL_LIB/lib/libcurl.a )

#For the static library:
#set ( CURL_LIBS libcurl.a )

add_compile_options(-DCURL_STATICLIB)



set( LIBRARY_INCLUDE_DIR C:/MinGW/CURL_LIB/include/)
include_directories(${LIBRARY_INCLUDE_DIR})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c" )

add_executable(test_curl ${SOURCES} )
target_link_libraries(test_curl ${CURL_LIBS} )


set_target_properties(curl
        PROPERTIES
        IMPORTED_LOCATION ${CURL_LIBS}
        )