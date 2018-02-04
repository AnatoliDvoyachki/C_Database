#pragma once

static const char ASSIGNMENT_FORMAT[] = "A %d %d"; // the format of a assignment entry

typedef struct assignment* assignment_t; // assignment ADT

assignment_t create_assignment(int teacher_number, int course_number); // creates an assignment in the memory

void destroy_assignment(assignment_t self); // removes an assignment from the memory

int get_assignment_teacher_number(assignment_t self); // returns the teacher number of an assignment

int get_assignment_course_number(assignment_t self); // returns the course number of an assignment

void print_assignment(assignment_t self); // prints the attributes of an assignment
