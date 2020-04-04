#include "studentlist.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	Student ms;
	struct Node *pnext;
}Node;

struct List {
	int gsize;
	Node *gpfirst;
};

ListHandle create_list(void)
{
	ListHandle handle = (ListHandle)malloc(sizeof(*handle));
	if (!handle) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	handle->gpfirst = NULL;
	handle->gsize = 0;
	return handle;
}


void close_list(ListHandle handle)
{
	make_empty(handle);
	free(handle);
}


void push_front(ListHandle handle, const struct Student *p)
{
	Node *pnewnode = (Node*)malloc(sizeof(Node));
	if (!pnewnode) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	pnewnode->ms = *p;
	pnewnode->pnext = handle->gpfirst;
	handle->gpfirst = pnewnode;
	++handle->gsize;
}
//----------------------------------------------------------------------------------------------------
void pop_front(ListHandle handle)
{
	if (is_empty(handle)) {
		printf("bos liste hatasi!!!!\n");
		exit(EXIT_FAILURE);
	}
	Node *p = handle->gpfirst;
	handle->gpfirst = handle->gpfirst->pnext;
	free(p);
	--handle->gsize;
}

//----------------------------------------------------------------------------------------------------
struct Student *get_top(ListHandle handle, struct Student *p)
{
	if (is_empty(handle)) {
		printf("bos liste hatasi!!!!\n");
		exit(EXIT_FAILURE);
	}
	*p = handle->gpfirst->ms;
	return p;
}

//----------------------------------------------------------------------------------------------------
size_t get_size(ListHandle handle)
{
	return handle->gsize;
}
//----------------------------------------------------------------------------------------------------
int is_empty(ListHandle handle)
{
	return handle->gpfirst == NULL;
}
//----------------------------------------------------------------------------------------------------
void print_list(ListHandle handle)
{
	for (Node *ptr = handle->gpfirst; ptr != NULL; ptr = ptr->pnext) {
		print_student(&ptr->ms);
	}
}
//----------------------------------------------------------------------------------------------------
void make_empty(ListHandle handle)
{
	while (!is_empty(handle))
		pop_front(handle);
}
//----------------------------------------------------------------------------------------------------
