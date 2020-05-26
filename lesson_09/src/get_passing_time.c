/**
 * @file    : LESSON_9 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / May / 2020
 * @code    : get_passing_time.c file
 * @details : 
 */

#include <stdio.h>

typedef struct {
    int day;
    int hour;
    int minute;
    int second;
}TIME_t;

void get_passing_time(TIME_t *p_time)
{
    p_time->minute += p_time->second / 60;
    p_time->second %= 60;

    p_time->hour += p_time->minute / 60;
    p_time->minute %= 60;

    p_time->day += p_time->hour / 24;
    p_time->hour %= 24;
}


int main(void)
{
    TIME_t time = {0};

    printf("Enter the time as Day, Hour, Minute and Second : \n");
    scanf("%d%d%d%d", &time.day, &time.hour, &time.minute, &time.second);

    get_passing_time(&time);

    printf("%d Day %d Hour %d Minute %d Second\n", time.day, time.hour, time.minute, time.second);

    return 0;
}


