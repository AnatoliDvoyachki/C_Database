#define _CRT_SECURE_NO_WARNINGS // ignore the strcpy() function warnings
#include "student_adt.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 50

struct student
{
	int student_number;
	char first_name[MAX_LENGTH];
};

student_t create_student(int student_number, char* first_name)
{
	student_t new_student = (student_t)malloc(sizeof(struct student));
	if (new_student == NULL)
	{
		return NULL; // out of memory
	}
	new_student->student_number = student_number;
	strcpy(new_student->first_name, first_name);
	return new_student;
}

void destroy_student(student_t self)
{
	free(self);
}

int get_student_number(student_t self)
{
	return self->student_number;
}

char* get_student_first_name(student_t self)
{
	return self->first_name;
}

void print_student(student_t self)
{
	printf(STUDENT_FORMAT, get_student_number(self), get_student_first_name(self));
	printf("\n");
}
