/*
  Project Name: LESSON_14
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 06 / Ocak / 2020	
  File Description: macros_definitions.c file contains definitions of some macros.
*/

#define     bool        _Bool
#define     tamsayi     int
#define     ERROR_MSG   "Unsufficient Memory !\n"

#ifdef ERROR_MSG
#define     MAX         100
#else
#define     MAX         400
#endif


#define     MIN         100
#undef      MIN
#define     MIN         400



#include <stdio.h>

int main(void)
{
    tamsayi x;
    printf("Enter a number : ");
    scanf("%d", &x);

    bool true  = 1;
    bool false = 0;

    printf("True : %d\n", true);
    printf("False : %d\n", false);

    printf(ERROR_MSG);

    printf("MAX : %d", MAX);

    return 0;
}

