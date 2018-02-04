#include "assignment_adt.h"
#include <stdlib.h>
#include <stdio.h>

struct assignment
{
	int teacher_number, course_number;
};

assignment_t create_assignment(int teacher_number, int course_number)
{
	assignment_t new_assignment = (assignment_t)malloc(sizeof(struct assignment));
	if (new_assignment == NULL)
	{
		return NULL; // out of memory
	}
	new_assignment->teacher_number = teacher_number;
	new_assignment->course_number = course_number;
	return new_assignment;
}

void destroy_assignment(assignment_t self)
{
	free(self);
}

int get_assignment_course_number(assignment_t self)
{
	return self->course_number;
}

int get_assignment_teacher_number(assignment_t self)
{
	return self->teacher_number;
}

void print_assignment(assignment_t self)
{
	printf(ASSIGNMENT_FORMAT, get_assignment_teacher_number(self), get_assignment_course_number(self));
	printf("\n");
}
