cmake_minimum_required(VERSION 3.15)
project(LESSON_28 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)


#For the shared library:
#set ( PROJECT_LINK_LIBS liblog_file_name_generator.dll )

#For the static library:
set ( LOG_FILE_NAME_GENERATOR_LIBS liblog_file_name_generator.a )

set( LIBRARY_BUILD_DIR ../libs/log_file_name_generator/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/log_file_name_generator/include)
include_directories(${LIBRARY_INCLUDE_DIR})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c" "includes/*.h")

add_executable(locale_test ${SOURCES})
target_link_libraries(locale_test ${LOG_FILE_NAME_GENERATOR_LIBS} )