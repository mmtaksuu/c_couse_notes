/*
  Project Name: LESSON_15
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 09 / Ocak / 2020	
  File Description: function_like_macros_01.c file 
*/

// Definitions of some function-like moacros

#define     isleap(y)       ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define     max2(a, b)      ((a) > (b) ? (a) : (b))



#include <stdio.h>


// To not allow the preprecessor to replace the name of the func max2 with macro max2, we used () to indicate func's address.
int (max2)(int a, int b) {
    return printf("Func is called.\n"), a > b ? a : b;
}


int main(void)
{

    int x;
    printf("Enter a number : ");
    scanf("%d", &x);


    if isleap(x)
        printf("%d is a leap year\n", x);
    else
        printf("%d is not a leap year!\n", x);


    int a, b;
    printf("Enter two number : ");
    scanf("%d%d", &a, &b);

    // Finds maximum using function
    printf("The max of %d, %d is %d\n", a, b, (max2)(a, b));

    // Finds maximum using macro
    printf("The max of %d, %d is %d\n", a, b, max2(a, b));

    return 0;
}
