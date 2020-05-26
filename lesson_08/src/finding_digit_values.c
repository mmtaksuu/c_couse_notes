/**
 * @file    : LESSON_8 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : finding_digit_values.c file
 * @details : 
 */

#include <stdio.h>
#include <conio.h>
#include <ctype.h>


int ndigit(int x)
{
    int digit_cnt = 0;

    if (!x)
        return 1;

    while (x != 0) {
        ++digit_cnt;
        x /= 10;
    }

    return digit_cnt;
}

int power(int base, int exp)
{
    return exp == 0 ? 1 : base * power(base, exp -1);
}

void prints_digits(int ival, int nOfdigit)
{
    for (int i = 0; i < nOfdigit; ++i) {
        printf("%-10d digit is %d\n", power(10, i), ((ival/power(10, i))%10));
    }
}

int get_digit(int ival, int digit_no)
{
    return ((ival/power(10, digit_no))%10);
}


int main(void)
{
    int ival;
    printf("Enter a number :");
    scanf("%d", &ival);

    int nOfdigit = ndigit(ival);

    printf("Entered number has %d digit\n", nOfdigit);

    printf("\n");
    prints_digits(ival, nOfdigit);

    while (!_kbhit() && toupper(_getch() )!= 'Q') {
        int digit_no;
        printf("\nEnter digit no : ");
        scanf("%d", &digit_no);

        printf("%d\n", get_digit(ival, digit_no));
    }

    return 0;
}


