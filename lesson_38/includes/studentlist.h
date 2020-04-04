/**
 * @file    : c_programing_course project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / March / 2020
 * @code    : studentlist.c file
 * @details : 
 */

#ifndef STUDENTLIST_H
#define STUDENTLIST_H


#include <stddef.h>

struct Student;

void push_front(const struct Student *);
void pop_front(void);
struct Student *get_top(struct Student *p);
size_t get_size(void);
int is_empty();
void print_list(void);
void make_empty(void);



#endif //STUDENTLIST_H
