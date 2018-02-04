#define _CRT_SECURE_NO_WARNINGS // ignore strcpy() warnings
#include "teacher_adt.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 50

struct teacher
{
	int teacher_number;
	char first_name[MAX_LENGTH];
};

teacher_t create_teacher(int teacher_number, char* first_name)
{
	teacher_t new_teacher = (teacher_t)malloc(sizeof(struct teacher));
	if (new_teacher == NULL)
	{
		return NULL; // out of memory
	}
	new_teacher->teacher_number = teacher_number;
	strcpy(new_teacher->first_name, first_name);
	return new_teacher;
}

void destroy_teacher(teacher_t self)
{
	free(self);
}

int get_teacher_number(teacher_t self)
{
	return self->teacher_number;
}

char* get_teacher_first_name(teacher_t self)
{
	return self->first_name;
}

void print_teacher(teacher_t self)
{
	printf(TEACHER_FORMAT, get_teacher_number(self), get_teacher_first_name(self));
	printf("\n");
}
