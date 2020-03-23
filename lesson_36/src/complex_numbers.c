/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / March / 2020
 * @code    : complex_numbers.c file
 * @details : 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     randomize()       (srand((unsigned)time(NULL)))

typedef struct {
    double i;
    double j;
}COMPLEX_t;



COMPLEX_t* add_complex_numbers(COMPLEX_t *p1, COMPLEX_t *p2, COMPLEX_t *res)
{
    res->i = p1->i + p2->i;
    res->j = p1->j + p2->j;

    return res;
}

int main(void)
{

    randomize();
    COMPLEX_t num1, num2;
    num1.i = rand() % 100;
    num1.j = rand() % 10;

    num2.i = rand() % 100;
    num2.j = rand() % 10;

    printf("CMP1 is %.2f i + %.2f j\n", num1.i, num1.j);
    printf("CMP2 is %.2f i + %.2f j\n", num2.i, num2.j);

    COMPLEX_t res;
    add_complex_numbers(&num1, &num2, &res);
    printf("Sum of the num1 and num2 is %.2f i + %.2f j\n", res.i, res.j);

    return 0;
}


