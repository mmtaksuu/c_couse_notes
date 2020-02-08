/*
  Project Name: LESSON_20
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 25 / January / 2020	
  File Description: array_name_and_iter_variable_usage.c file describes the name of an array and iteration variables like i, are used for indicating array items in a for-loop.
                    a[i]   i[a] both are the same.
 */

int printf(const char *, ...);

#define     SIZE        10

int main(void)
{
    int a[SIZE] = { 218, 336, 693, 908, 379, 684, 412, 354, 295, 909, };

    for (int i = 0; i < SIZE; ++i)
        printf("i[a] = %d  |  a[i] = %d\n", i[a], a[i]);

    return 0;
}


