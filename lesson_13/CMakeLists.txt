cmake_minimum_required(VERSION 3.15)
project(LESSON_13 C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic-errors -Werror -Wconversion -Wsign-conversion)

#For the static library:
set ( UTILS_LIB libmy_lib.a )

set( LIBRARY_BUILD_DIR ../libs/my_lib/build)
link_directories( ${LIBRARY_BUILD_DIR} )

set( LIBRARY_INCLUDE_DIR ../libs/my_lib/include)
include_directories(${LIBRARY_INCLUDE_DIR})

add_executable(plots_random_numbers src/plots_random_numbers.c)
target_link_libraries(plots_random_numbers ${UTILS_LIB})



add_executable(for_loop_with_funcs src/for_loop_with_funcs.c)
add_executable(fibonacci_sequence_finder src/fibonacci_sequence_finder.c)
add_executable(calc_sum_of_series src/calc_sum_of_series.c)
add_executable(find_3rd_order_perfect_numbers src/find_3rd_order_perfect_numbers.c)


add_executable(plots_random_numbers_dynamically src/plots_random_numbers_dynamically.c)
target_link_libraries(plots_random_numbers_dynamically ${UTILS_LIB})

add_executable(unique_numbers_finder src/unique_numbers_finder.c)
target_link_libraries(unique_numbers_finder ${UTILS_LIB})

add_executable(find_all_factors src/find_all_factors.c)

add_executable(ders_13 src/ders_13.c)
target_link_libraries(ders_13 ${UTILS_LIB})