/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / September / 2020
 * @code    : display_current_time.c file
 * @details : 
 */


#include <time.h>
#include <stdio.h>


void display_current_time (void)
{
    static const char *const pmons[] = {
            "Ocak",
            "Subat",
            "Mart",
            "Nisan",
            "Mayis",
            "Haziran",
            "Temmuz",
            "Agustos",
            "Eylul",
            "Ekim",
            "Kasim",
            "Aralik"
    };

    static const char *const pdays[] = {
            "Pazar",
            "Pazartesi",
            "Sali",
            "Carsamba",
            "Persembe",
            "Cuma",
            "Cumartesi",
    };

    time_t timer = 0;
    time(&timer);

    struct tm * p = localtime(&timer);

    printf("%02d %s %04d %s - %02d:%02d:%02d\n", p->tm_mday, pmons[p->tm_mon], p->tm_year+1900, pdays[p->tm_wday],
           p->tm_hour, p->tm_min, p->tm_sec);

}


int main(void)
{
    display_current_time();

    return 0;
}



