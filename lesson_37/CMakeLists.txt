cmake_minimum_required(VERSION 3.15)
project(LESSON_37 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#add_definitions( -DCURL_STATICLIB )
#set(SRCS "src/test_libcurl.c")
#set( CURL_LIBRARY ${CMAKE_SOURCE_DIR}/lib )
#set( CURL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
#find_package( CURL )
#include_directories( ${CURL_INCLUDE_DIRS} )
#link_directories( ${CURL_LIBRARIES} )
#add_executable(curl_test ${SRCS})
#target_link_libraries(curl_test CURL)

add_executable(main src/main.c)


