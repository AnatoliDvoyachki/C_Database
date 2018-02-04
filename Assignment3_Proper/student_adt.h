#pragma once

static const char STUDENT_FORMAT[] = "S %d %s"; // the format of a student entry

typedef struct student* student_t; // student ADT

student_t create_student(int student_number, char* first_name); // creates a student in the memory

void destroy_student(student_t self); // removes a student from the memory

int get_student_number(student_t self); // returns the student number of a student

char* get_student_first_name(student_t self); // returns the first name of a student

void print_student(student_t self); // prints a student
