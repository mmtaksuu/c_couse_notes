#pragma once

#include "date.h"

typedef struct Student{
	int no_;
	char name_[16];
	char surname_[20];
	char town_[20];
	Date bdate_;
}Student;

Student* random_student(Student *);
void print_student(const Student *);

int cmpStudentbyName(const Student*, const Student *);
int cmpStudentbyTown(const Student*, const Student *);
int cmpStudentbySurname(const Student*, const Student *);
int cmpStudentbyNo(const Student*, const Student *);
int cmpStudentbyDate(const Student*, const Student *);