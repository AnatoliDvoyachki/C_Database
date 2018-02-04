#define _CRT_SECURE_NO_WARNINGS // ignore the warnings of strcpy()
#include "course_adt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

struct course
{
	int course_number, semester_number;
	char course_name[MAX_LENGTH];
};

course_t create_course(int course_number, char* course_name, int semester_number)
{
	course_t new_course = (course_t)malloc(sizeof(struct course));
	if (new_course == NULL)
	{
		return NULL; // out of memory
	}
	new_course->course_number = course_number;
	new_course->semester_number = semester_number;
	strcpy(new_course->course_name, course_name);
	return new_course;
}

void destroy_course(course_t self)
{
	free(self);
}

int get_course_number(course_t self)
{
	return self->course_number;
}

char* get_course_name(course_t self)
{
	return self->course_name;
}


int get_course_semester_number(course_t self)
{
	return self->semester_number;
}

void print_course(course_t self)
{
	printf(COURSE_FORMAT, get_course_number(self), get_course_name(self),
	       get_course_semester_number(self));
	printf("\n");
}
