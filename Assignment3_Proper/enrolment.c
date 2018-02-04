#include "enrolment_adt.h"
#include <stdlib.h>
#include <stdio.h>

struct enrolment
{
	int student_number, course_number;
};

enrolment_t create_enrolment(int student_number, int course_number)
{
	enrolment_t new_enrolment = (enrolment_t)malloc(sizeof(struct enrolment));
	if (new_enrolment == NULL)
	{
		return NULL; // out of memory
	}
	new_enrolment->student_number = student_number;
	new_enrolment->course_number = course_number;
	return new_enrolment;
}

void destroy_enrolment(enrolment_t self)
{
	free(self);
}

int get_enrollment_student_number(enrolment_t self)
{
	return self->student_number;
}

int get_enrollment_course_number(enrolment_t self)
{
	return self->course_number;
}

void print_enrolment(enrolment_t self)
{
	printf(ENROLMENT_FORMAT, get_enrollment_student_number(self), get_enrollment_course_number(self));
	printf("\n");
}
