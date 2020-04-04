#pragma once

#include <stddef.h>

struct List;
struct Student;

typedef struct List *ListHandle;

ListHandle create_list(void);
void close_list(ListHandle);

void push_front(ListHandle, const struct Student *);
void pop_front(ListHandle);
struct Student *get_top(ListHandle, struct Student *p);
size_t get_size(ListHandle);
int is_empty(ListHandle);
void print_list(ListHandle);
void make_empty(ListHandle);

