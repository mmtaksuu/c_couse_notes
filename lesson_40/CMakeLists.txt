cmake_minimum_required(VERSION 3.15)
project(LESSON_40 C)

set(CMAKE_C_STANDARD 99)

# lots of warnings and all warnings as errors
#add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#For the static library:
set ( UTILS_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(random_set_reset_bits src/random_set_reset_bits.c)
target_link_libraries(random_set_reset_bits ${UTILS_LIB})

add_executable(check_given_number src/check_given_number.c)
target_link_libraries(check_given_number ${UTILS_LIB})

add_executable(print_bits_func src/print_bits_func.c)
target_link_libraries(print_bits_func ${UTILS_LIB})

add_executable(print_hex_bits src/print_hex_bits.c)

add_executable(random_set_reset_2 src/random_set_reset_2.c)
target_link_libraries(random_set_reset_2 ${UTILS_LIB})

add_executable(prints_bits_functions src/prints_bits_functions.c)


add_executable(uretim_kritik_01 src/uretim_kritik_01.c)
#add_executable(uretim_kritik_02 src/uretim_kritik_02.c)
#add_executable(uretim_kritik_03 src/uretim_kritik_03.c)
#add_executable(uretim_kritik_04 src/uretim_kritik_04.c)
#add_executable(uretim_kritik_05 src/uretim_kritik_05.c)
#add_executable(uretim_kritik_06 src/uretim_kritik_06.c)
#add_executable(test01 src/test01.c)
#add_executable(test02 src/test02.c)
#add_executable(test03 src/test03.c)
#add_executable(test04 src/test04.c)



