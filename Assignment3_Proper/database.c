#define _CRT_SECURE_NO_WARNINGS // ignore the warnings from fopen() and sscanf()
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "list_adt.h"
#include "database.h"
#include "student_adt.h"
#include "teacher_adt.h"
#include "course_adt.h"
#include "assignment_adt.h"
#include "enrolment_adt.h"

#define MAX_LENGTH 255
#define FILE_NAME "databaseInput.txt" // name of the textfile that stores the information
#define MODE_READ "r" // read setting for fopen()

list_t student_list; // stores the students
list_t teacher_list; // stores the teachers
list_t course_list; // stores the courses
list_t enrolment_list; // stores the enrolments
list_t assignment_list; // stores the assignments

bool student_has_been_removed = false;
// variable to track if any element has been removed from the student and enrolments list
list_t student_cache; // stores the removed students
list_t enrolment_cache; // stores the removed enrolments

// helper function that creates all the lists
void initialize_lists()
{
	student_list = create_list();
	teacher_list = create_list();
	course_list = create_list();
	enrolment_list = create_list();
	assignment_list = create_list();

	student_cache = create_list(); // cache for removed students
	enrolment_cache = create_list(); // cache for the removed student's enrolments
}

// helper function to print all the students in the student list
void print_student_list()
{
	int size = no_of_items(student_list);
	for (int i = 0; i < size; i++)
	{
		student_t student = get_item(student_list, i);
		print_student(student);
	}
}

// helper function to print all the teachers in the teacher list
void print_teacher_list()
{
	int size = no_of_items(teacher_list);
	for (int i = 0; i < size; i++)
	{
		teacher_t teacher = get_item(teacher_list, i);
		print_teacher(teacher);
	}
}

// helper function to print all the courses in the course list
void print_course_list()
{
	int size = no_of_items(course_list);
	for (int i = 0; i < size; i++)
	{
		course_t course = get_item(course_list, i);
		print_course(course);
	}
}

// helper function to print all the enrolments in the enrolment list
void print_enrolment_list()
{
	int size = no_of_items(enrolment_list);
	for (int i = 0; i < size; i++)
	{
		enrolment_t enrolment = get_item(enrolment_list, i);
		print_enrolment(enrolment);
	}
}

// helper function to print all the assignments in the assignment list
void print_assignment_list()
{
	int size = no_of_items(assignment_list);
	for (int i = 0; i < size; i++)
	{
		assignment_t assignment = get_item(assignment_list, i);
		print_assignment(assignment);
	}
}

void print_database()
{
	print_student_list();
	print_teacher_list();
	print_course_list();
	print_enrolment_list();
	print_assignment_list();
}


void populate_database()
{
	initialize_lists(); // create all the lists
	char line[MAX_LENGTH], second_attribute[MAX_LENGTH]; // temporary variables
	int first_attribute = 0, third_attribute = 0; // temporary variables
	FILE* text_file; // pointer to the text file
	fopen_s(&text_file, FILE_NAME, MODE_READ); // open the text file
	while (fgets(line, MAX_LENGTH, text_file) != NULL) // loop until you reach the end of the file 
	{
		if (sscanf(line, STUDENT_FORMAT, &first_attribute, second_attribute) == 2) // read a student line
		{
			add_item(student_list, create_student(first_attribute, second_attribute)); // add it to the list
		}
		if (sscanf(line, TEACHER_FORMAT, &first_attribute, second_attribute) == 2) // read a teacher line
		{
			add_item(teacher_list, create_teacher(first_attribute, second_attribute)); // add it to the list
		}
		if (sscanf(line, COURSE_FORMAT, &first_attribute, second_attribute, &third_attribute) == 3) // read a course line
		{
			add_item(course_list, create_course(first_attribute, second_attribute, third_attribute)); // add it to the list
		}
		if (sscanf(line, ASSIGNMENT_FORMAT, &first_attribute, &third_attribute) == 2) // read an assignment line
		{
			add_item(assignment_list, create_assignment(first_attribute, third_attribute)); // add it to the list
		}
		if (sscanf(line, ENROLMENT_FORMAT, &first_attribute, &third_attribute) == 2) // read an enrolment line
		{
			add_item(enrolment_list, create_enrolment(first_attribute, third_attribute)); // add it to the list
		}
	}
	fclose(text_file); // close the input stream
}

// helper function for query_for_students_by_course_number() that checks 
// if students with the course number as parameter exists in the database
bool course_exists(int course_number)
{
	int size = no_of_items(course_list);
	for (int i = 0; i < size; i++)
	{
		course_t course = get_item(course_list, i);
		if (get_course_number(course) == course_number)
		{
			return true;
		}
	}
	return false;
}

// helper function for get_student() that returns true if 
// a student exists in the database. otherwise false
bool student_exists(list_t student_source, int student_number)
{
	int size = no_of_items(student_source);
	for (int i = 0; i < size; i++)
	{
		student_t student = get_item(student_source, i);
		if (get_student_number(student) == student_number)
		{
			return true;
		}
	}
	return false;
}

// helper function for remove_student() that finds and returns an existing student.
// if the student does not exist, returns nothing
student_t get_student(int student_number)
{
	if (!student_exists(student_list, student_number))
	{
		return; // student does not exist
	}
	int size = no_of_items(student_list);
	for (int i = 0; i < size; i++)
	{
		student_t student = get_item(student_list, i);
		if (get_student_number(student) == student_number)
		{
			return student;
		}
	}
	return;
}

// helper function that returns true of a teacher with the 
// number as parameter exists in the database. otherwise false
bool teacher_exists(int teacher_number)
{
	int size = no_of_items(teacher_list);
	for (int i = 0; i < size; i++)
	{
		teacher_t teacher = get_item(teacher_list, i);
		if (get_teacher_number(teacher) == teacher_number)
		{
			return true;
		}
	}
	return false;
}

// helper function that returns true if an enrolment has the student and
// course numbers. otherwise false
bool enrolment_exists(int course_number, int student_number)
{
	int size = no_of_items(enrolment_list);
	for (int i = 0; i < size; i++)
	{
		enrolment_t enrolment = get_item(enrolment_list, i);
		if (get_enrollment_student_number(enrolment) == student_number &&
			get_enrollment_course_number(enrolment) == course_number)
		{
			return true;
		}
	}
	return false;
}

// helper function that returns true if an assignment with the 
// teacher number and course number as parameters exists. otherwise false 
bool assignment_exists(int teacher_number, int course_number)
{
	int size = no_of_items(assignment_list);
	for (int i = 0; i < size; i++)
	{
		assignment_t assignment = get_item(assignment_list, i);
		if (get_assignment_teacher_number(assignment) == teacher_number &&
			get_assignment_course_number(assignment) == course_number)
		{
			return true;
		}
	}
	return false;
}

// helper function to check if user input is a digit. 
// returns true if it is, otherwise false
bool is_number(const char* number)
{
	while (*number)
	{
		if (isdigit(*number++) == 0)
		{
			return false;
		}
	}
	return true;
}

// helper function that returns true if a student has an enrolment, and false otherwise
bool has_enrolment(int student_number)
{
	int size = no_of_items(enrolment_list);
	enrolment_t enrolment;
	for (int i = 0; i < size; i++)
	{
		enrolment = get_item(enrolment_list, i);
		if (get_enrollment_student_number(enrolment) == student_number)
		{
			return true;
		}
	}
	return false;
}

// helper function to remove the student's enrolments after the student has been removed
void remove_enrolment(int student_number)
{
	enrolment_t enrolment;
	for (int i = 0; i < no_of_items(enrolment_list); i++)
	{
		enrolment = get_item(enrolment_list, i);
		if (get_enrollment_student_number(enrolment) == student_number)
		{
			add_item(enrolment_cache, enrolment); // cache the enrolment
			remove_item(enrolment_list, enrolment);
		}
	}
}

int remove_student(int student_number)
{
	student_t student = NULL;
	student = get_student(student_number);
	if (student == NULL)
	{
		printf("Student with number %d does not exist!", student_number);
		return 0; // student does not exist
	}
	add_item(student_cache, student); // cache the student
	remove_item(student_list, student); // remove the student
	while (has_enrolment(student_number))
	{
		remove_enrolment(student_number); // remove the all enrolments of the student
	}
	student_has_been_removed = true; // indicate that a change in the student list has occured
	printf("Student with number %d removed!", student_number);
	return 1; // removal successful
}

void query_for_students_by_course_number(char* search_value)
{
	if (!is_number(search_value))
	{
		printf("%s is not a number!", search_value);
		return; // not a digit
	}
	int course_number = atoi(search_value); // parse to integer
	if (!course_exists(course_number))
	{
		printf("Course with course number %s does not exist!", search_value);
		return; // course does not exist
	}
	printf("Students enrolled into the course:\n");
	int size = no_of_items(student_list);
	for (int i = 0; i < size; i++)
	{
		student_t student = get_item(student_list, i);
		int student_number = get_student_number(student);
		if (enrolment_exists(course_number, student_number))
		{
			print_student(student); // if a student is enrolled into the course, the student 
			// is printed
		}
	}
}

void query_for_courses_by_student_number(char* search_value)
{
	if (!is_number(search_value))
	{
		printf("%s is not a number!", search_value);
		return; // not a digit
	}
	int student_number = atoi(search_value);
	if (!student_exists(student_list, student_number))
	{
		printf("Student with number %s does not exist!", search_value);
		return; // if student with the number passed as a parameter 
		// does not exist in the databse, print message and reutrn
	}
	printf("The student with number %d is enrolled into these courses:\n", student_number);
	int size = no_of_items(course_list);
	for (int i = 0; i < size; i++) // go through all courses in the course list
	{
		course_t course = get_item(course_list, i);
		int course_number = get_course_number(course);
		if (enrolment_exists(course_number, student_number)) // check which student is enrolled into a course
		{
			print_course(course);
		}
	}
}

void query_for_courses_by_teacher_number(char* search_value)
{
	if (!is_number(search_value))
	{
		printf("%s is not a number!\n", search_value);
		return; // not a digit
	}
	int teacher_number = atoi(search_value);
	if (!teacher_exists(teacher_number))
	{
		printf("Teacher with number %s does not exist!", search_value);
		return; // teacher does not exist
	}
	printf("The teacher with number %d is assigned to these courses:\n", teacher_number);
	int size = no_of_items(course_list);
	for (int i = 0; i < size; i++) // go through all courses
	{
		course_t course = get_item(course_list, i);
		int course_number = get_course_number(course);
		if (assignment_exists(teacher_number, course_number))
		{
			print_course(course); // if a teacher teaches this course print the course
		}
	}
}

void query_for_teachers_by_student_number(list_t student_source, list_t enrolment_source, char* search_value)
{
	if (!is_number(search_value))
	{
		printf("%s is not a number!\n", search_value);
		return; // not a digit
	}
	int student_number = atoi(search_value); // convert the student number from a string to integer
	if (!student_exists(student_source, student_number) && !student_has_been_removed)
	{
		printf("Student with number %s does not exist!", search_value);
		return; // student does not exist
	}
	int course_numbers[MAX_LENGTH]; // used to store course numbers of the courses that the student is enrolled in
	int size = no_of_items(enrolment_source), index = 0;
	for (int i = 0; i < size; i++)
	{
		enrolment_t enrolment = get_item(enrolment_source, i);
		if (get_enrollment_student_number(enrolment) == student_number)
		{
			course_numbers[index++] = get_enrollment_course_number(enrolment); 
		}
	}
	printf("Student with number %d has been taught by:\n", student_number);
	int no_of_teachers = no_of_items(teacher_list);
	for (int i = 0; i < no_of_teachers; i++)
	{
		teacher_t teacher = get_item(teacher_list, i);
		for (int j = 0; j < index; j++)
		{
			if (assignment_exists(get_teacher_number(teacher), course_numbers[j]))
			{
				print_teacher(teacher);
			}
		}
	}
}

void query(int for_what, int by_what, char* search_value)
{
	if (for_what == FOR_STUDENTS)
	{
		if (by_what == BY_COURSE_NUMBER)
		{
			query_for_students_by_course_number(search_value); // which students are enrolled into a course
		}
	}
	else if (for_what == FOR_COURSES)
	{
		if (by_what == BY_STUDENT_NUMBER)
		{
			query_for_courses_by_student_number(search_value); // which courses is a student enrolled in
		}
		else if (by_what == BY_TEACHER_NUMBER)
		{
			query_for_courses_by_teacher_number(search_value); // which courses does a teacher teach
		}
	}
	else if (for_what == FOR_TEACHERS)
	{
		if (by_what == BY_STUDENT_NUMBER) // which teachers are teaching or have taught a student
		{
			if (student_has_been_removed) // if a student has been removed, access the cache
			{
				query_for_teachers_by_student_number(student_cache, enrolment_cache, search_value);
			}
			// after that only access the regular lists
			query_for_teachers_by_student_number(student_list, enrolment_list, search_value);
		}
	}
}
