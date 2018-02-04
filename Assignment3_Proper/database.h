#pragma once
#include <stdbool.h>
#include "student_adt.h"

// constants for the querying functionality
static const int FOR_STUDENTS = 1;
static const int FOR_TEACHERS = 2;
static const int FOR_COURSES = 3;

static const int BY_STUDENT_NUMBER = 1;
static const int BY_TEACHER_NUMBER = 2;
static const int BY_COURSE_NUMBER = 3;

void print_database(); // prints all the data from the text file

void populate_database(); // reads all entries from the text file and populates the lists

void query(int for_what, int by_what, char* search_value); // prints data that matches the criteria passed by the user

// removes a student from the database. returns 1 if successful, 0 if unsuccessful
int remove_student(int student_number);

#ifdef UNIT_TEST_PRIVATE_FUNCTIONS
// the following functions are only used as helpers inside the main functions defined above. 
// these functions are added here only so they could be unit tested in the database_unit_test.c file,
// the rest of the time they are blocked with #ifdef and #endif

student_t get_student(int student_number);

bool teacher_exists(int teacher_number);

bool enrolment_exists(int course_number, int student_number);

bool assignment_exists(int teacher_number, int course_number);

bool is_number(const char* number);

bool has_enrolment(int student_number);

#endif
