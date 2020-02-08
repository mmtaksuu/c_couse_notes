/*
  Project Name: LESSON_13
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 03 / Ocak / 2020	
  File Description: main.c file returns the multipliers of the given number. For exp : x is 34 then output : 2 17.
*/

int printf(const char *ptr, ...);
int scanf(const char *ptr, ...);


void find_multipliers(int x)
{
    int n = 2;

    while (x != 1) {
        while (x % n == 0) {
            printf("%d ", n);
            x /= n;
        }
        ++n;
    }
}


int main()
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    find_multipliers(x);

    return 0;
}


