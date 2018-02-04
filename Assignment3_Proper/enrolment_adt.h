#pragma once

static const char ENROLMENT_FORMAT[] = "E %d %d"; // the format of an enrolment entry

typedef struct enrolment* enrolment_t; // enrolment ADT

enrolment_t create_enrolment(int course_number, int student_number); // creates a new enrolment in the memory

void destroy_enrolment(enrolment_t self); // removes an enrolment from the memory

int get_enrollment_course_number(enrolment_t self); // returns the course number of an enrolment

int get_enrollment_student_number(enrolment_t self); // returns the student number of an enrolment

void print_enrolment(enrolment_t self); // prints the attributes of an enrolment 
