/**
 * @file    : c_programing_course project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : studentlist.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "studentlist.h"



typedef struct Node{
    Student ms;
    struct Node *pnext;
}Node;

static int gsize = 0;
static Node *gpfirst = NULL;

void push_front(const struct Student *p)
{
    Node *pnewnode = (Node*)malloc(sizeof(Node));
    if (!pnewnode) {
        printf("bellek yetersiz\n");
        exit(EXIT_FAILURE);
    }
    pnewnode->ms = *p;
    pnewnode->pnext = gpfirst;
    gpfirst = pnewnode;
    ++gsize;
}
//----------------------------------------------------------------------------------------------------
void pop_front()
{
    if (is_empty()) {
        printf("bos liste hatasi!!!!\n");
        exit(EXIT_FAILURE);
    }
    Node *p = gpfirst;
    gpfirst = gpfirst->pnext;
    free(p);
    --gsize;
}

//----------------------------------------------------------------------------------------------------
struct Student *get_top(struct Student *p)
{
    if (is_empty()) {
        printf("bos liste hatasi!!!!\n");
        exit(EXIT_FAILURE);
    }
    *p = gpfirst->ms;
    return p;
}

//----------------------------------------------------------------------------------------------------
size_t get_size(void)
{
    return gsize;
}
//----------------------------------------------------------------------------------------------------
int is_empty()
{
    return gpfirst == NULL;
}
//----------------------------------------------------------------------------------------------------
void print_list(void)
{
    for (Node *ptr = gpfirst; ptr != NULL; ptr = ptr->pnext) {
        print_student(&ptr->ms);
    }
}
//----------------------------------------------------------------------------------------------------
void make_empty(void)
{
    while (!is_empty())
        pop_front();
}

