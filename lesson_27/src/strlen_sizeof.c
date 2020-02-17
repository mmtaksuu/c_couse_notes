/*
  Project Name: LESSON_27
  Author: MEHMET AKSU	
  Author Email: mmtaksu.25@gmail.com
  Date: 16 / February / 2020	
  File Description: strlen_sizeof.c file 
*/


#include <stdio.h>



void puts_(const char *p)
{
    while (*p != '\0'){
        putchar(*p);
        ++p;
    }
    putchar('\n');

}


size_t strlen_(const char *p)
{
    size_t len = 0;

    while (*p++ != '\0')
        ++len;

    return len;
}




int main(void)
{
    char str[] = "Bu ders C kursunun 27.incisidir.";

    puts_(str);

    printf("without null character: %u\n", strlen_(str));
    printf("with null character:    %u\n", sizeof str);


    return 0;
}
