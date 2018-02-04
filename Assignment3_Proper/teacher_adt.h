#pragma once

static const char TEACHER_FORMAT[] = "T %d %s"; // the format of a teacher entry

typedef struct teacher* teacher_t; // teacher ADT

teacher_t create_teacher(int teacher_number, char* first_name); // creates a teacher in the memory

void destroy_teacher(teacher_t self); // removes a teacher from the memory

int get_teacher_number(teacher_t self); // returns the teacher number of a teacher

char* get_teacher_first_name(teacher_t self); // returns the first name of a teacher

void print_teacher(teacher_t self); // prints a teacher
