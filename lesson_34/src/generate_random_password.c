/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 12 / September / 2020
 * @code    : generate_random_password.c file
 * @details : 
 */

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define     randomize()       (srand((unsigned)time(NULL)))


int get_rand_char(void)
{
    int ch;
    while (!isalnum(ch = rand() % 128))
        ;
    return ch;
}


/** Generates random password by passing a string argument */
char * get_rand_psw_1 (char *p)
{
    char * ptemp = p;

    size_t len = rand() % 10 + 5;
    while (len--) {
        *p++ = (char)get_rand_char();
    }
    *p = '\0';

    return ptemp;
}


/** Generates random password by allocating dynamic memory */
char * get_rand_psw_2 (void)
{
    size_t len = rand() % 10 + 5;

    char * pd = (char *)malloc(len+1);
    if (!pd) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t i = 0;

    while (len--) {
        pd[i++] = (char)get_rand_char();
    }
    pd[i] = '\0';

    return pd;
}


/** Generates random password by returning static object address */
char * get_rand_psw_3 (void)
{
    static char str[100];

    size_t len = rand() % 10 + 5;
    size_t i = 0;

    while (len--) {
        str[i++] = (char)get_rand_char();
    }
    str[i] = '\0';

    return str;
}


void test1(void)
{
    char psw[100];
    get_rand_psw_1(psw);
    printf("Password : %s\n", psw);
}

void test2(void)
{
    char * pd = get_rand_psw_2();
    printf("Password : %s\n", pd);
    free(pd);
    pd = NULL;
}

void test3(void)
{
    printf("Password : %s\n", get_rand_psw_3());
}


int main(void)
{
    randomize();

    test1();

    test2();

    test3();

    return 0;
}



