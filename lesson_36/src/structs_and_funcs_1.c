/**
 * @file    : LESSON_36 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / March / 2020
 * @code    : structs_and_funcs_1.c file
 * @details : 
 */

#include <stdio.h>

typedef struct {
    int age;
    char name[20];
    char surname[20];
} Student_t;


Student_t * set_student(Student_t *p)
{
    printf("p->age : ");
    scanf("%d", &p->age);

    printf("p->name : ");
    scanf("%s", p->name);

    printf("p->surname : ");
    scanf("%s", p->surname);

    return p;
}


void get_student(const Student_t *p)
{
    printf("p->age     : %d\n", p->age);
    printf("p->name    : %s\n", p->name);
    printf("p->surname : %s\n", p->surname);
}


int main(void)
{
    printf("Enter the Student Information : \n");
    Student_t p;
    set_student(&p);
    printf("\n\n");

    get_student(&p);

    return 0;
}



