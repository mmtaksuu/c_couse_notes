cmake_minimum_required(VERSION 3.15)
project(LESSON_41 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

option(lib_type "Build static library" ON)

if(lib_type)
    set ( CURL_LIB libcurl.a ) # STATIC
else()
    set ( CURL_LIB libcurl.dll.a ) # SHARED
endif()


set( LIBRARY_LINK_DIR C:/curl-7.69.1-win64-mingw/lib/)
link_directories( ${LIBRARY_LINK_DIR} )

set( LIBRARY_INCLUDE_DIR C:/curl-7.69.1-win64-mingw/include/curl/)
include_directories(${LIBRARY_INCLUDE_DIR})
add_executable(babil_algorithm src/babil_algorithm.c)
add_executable(randomize src/randomize.c)
add_executable(path_splitting src/path_splitting.c)
add_executable(find_dist_on_the_earth src/find_dist_on_the_earth.c)


add_executable(curl_test_client src/curl_test01.c)
target_link_libraries(curl_test_client PUBLIC ${CURL_LIB})


#find_library(CURL_LIB curl_library lib)
#target_link_libraries(curl_test_client LINK_PUBLIC libcurl)


