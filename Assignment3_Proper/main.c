#define _CRT_SECURE_NO_WARNINGS // ignore scanf() warnings
#include "database.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_LENGTH 255 // user input array size constant
// menu option constants
#define EXECUTE_EXIT 0
#define EXECUTE_PRINT_ALL_DATA 1
#define EXECUTE_QUERY_FOR_STUDENTS_BY_COURSE_NUMBER 2
#define EXECUTE_QUERY_FOR_COURSES_BY_STUDENT_NUMBER 3
#define EXECUTE_QUERY_FOR_COURSES_BY_TEACHER_NUMBER 4
#define EXECUTE_QUERY_FOR_TEACHERS_BY_STUDENT_NUMBER 5
#define EXECUTE_REMOVE_STUDENT 6

// function that contains the user menu logic
void start()
{
	populate_database(); // fetches the data only once when the program is started
	char text_input[MAX_LENGTH];
	int user_choice = 0;
	do
	{
		printf("\n");
		printf("%s\n", "Main menu");
		printf("%d. %s\n", 0, "Exit");
		printf("%d. %s\n", 1, "Print all data");
		printf("%d. %s\n", 2, "Which students are enrolled into a course?");
		printf("%d. %s\n", 3, "Which courses is a student enrolled into?");
		printf("%d. %s\n", 4, "Which courses does a teacher teach?");
		printf("%d. %s\n", 5, "Which teachers have taught a student?");
		printf("%d. %s\n", 6, "Remove student");
		printf("\n");
		scanf("%d", &user_choice); // read  and save the user choice
		switch (user_choice) // execute whatever the user wants
		{
		case EXECUTE_EXIT:
			{
				exit(0);
			}
		case EXECUTE_PRINT_ALL_DATA:
			{
				print_database();
			}
			break;
		case EXECUTE_QUERY_FOR_STUDENTS_BY_COURSE_NUMBER:
			{
				print_database();
				printf("\nEnter the number of the course:\n");
				scanf("%s", text_input);
				printf("\n");
				query(FOR_STUDENTS, BY_COURSE_NUMBER, text_input);
				printf("\n");
			}
			break;
		case EXECUTE_QUERY_FOR_COURSES_BY_STUDENT_NUMBER:
			{
				print_database();
				printf("\nEnter the number of the student:\n");
				scanf("%s", text_input);
				printf("\n");
				query(FOR_COURSES, BY_STUDENT_NUMBER, text_input);
				printf("\n");
			}
			break;
		case EXECUTE_QUERY_FOR_COURSES_BY_TEACHER_NUMBER:
			{
				print_database();
				printf("\nEnter the number of the teacher:\n");
				scanf("%s", text_input);
				printf("\n");
				query(FOR_COURSES, BY_TEACHER_NUMBER, text_input);
				printf("\n");
			}
			break;
		case EXECUTE_QUERY_FOR_TEACHERS_BY_STUDENT_NUMBER:
			{
				print_database();
				printf("\nEnter the number of the student:\n");
				scanf("%s", text_input);
				printf("\n");
				query(FOR_TEACHERS, BY_STUDENT_NUMBER, text_input);
				printf("\n");
			}
			break;
		case EXECUTE_REMOVE_STUDENT:
			{
				print_database();
				printf("\nEnter the number of the student to remove:\n");
				int student_number = 0;
				scanf("%d", &student_number);
				printf("\n");
				remove_student(student_number);
				printf("\n");
			}
			break;
		default:
			printf("%s\n", "Invalid input");
			break;
		}
	}
	while (1);
}

int main()
{
	start();
	while (1);
}
