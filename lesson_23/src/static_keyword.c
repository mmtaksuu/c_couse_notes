/**
 * @file    : LESSON_23 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / March / 2020
 * @code    : static_keyword.c file
 * @details : 
 */


#include <stdio.h>

void func(void)
{
    static int x = 0, y = 0, z = 0;
    printf("%d %d %d\n", x, y, z);
    ++x, ++y, ++z;
}


int main(void)
{
    printf("x y z\n");
    for (int i = 0; i < 10; ++i) {
        func();
    }

    return 0;
}
