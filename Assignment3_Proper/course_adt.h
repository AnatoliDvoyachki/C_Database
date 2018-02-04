#pragma once

static const char COURSE_FORMAT[] = "C %d %s %d"; // the format of a course entry

typedef struct course* course_t; // course ADT

course_t create_course(int course_number, char* course_name, int semester_number); // creates a new course in the memory

void destroy_course(course_t self); // removes a course from the memory

int get_course_number(course_t self); // returns the course number of a course

char* get_course_name(course_t self); // returns the course name of a course

int get_course_semester_number(course_t self); // returns the semeter number of a course 

void print_course(course_t self); // prints the attributes of a course
