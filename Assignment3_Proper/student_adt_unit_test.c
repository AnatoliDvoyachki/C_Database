#include "student_adt.h"
#include "minunit.h"
#include <stdio.h>
#include <string.h>

// Unit test for the student ADT

#ifdef STUDENT_ADT_UNIT_TEST
int tests_run = 0;

// Function parameter constants
const int student_number = 123456;
const char student_name[] = "Anatoli";


static char* test_create_student_successful()
{
	student_t new_student = NULL;
	new_student = create_student(student_number, student_name);
	mu_assert("test_create_student_successful: student == NULL", new_student != NULL);
	mu_assert("student_number != 123456", get_student_number(new_student) == student_number);
	mu_assert("first_name != Anatoli", strcmp(get_student_first_name(new_student), student_name) == 0);
	// library function strcmp() returns 0 when two strings are the same
}

static char* test_get_student_number()
{
	student_t test_student = create_student(student_number, student_name);
	mu_assert("test_get_student_number: 123456 != 123456", get_student_number(test_student) == student_number);
}

static char* test_get_student_name()
{
	student_t test_student = create_student(student_number, student_name);
	mu_assert("test_get_student_name: Anatoli != Anatoli", strcmp(get_student_first_name(test_student), student_name) == 0);
}


static char* all_tests()
{
	mu_run_test(test_create_student_successful);
	mu_run_test(test_get_student_number);
	mu_run_test(test_get_student_name);
}

int main()
{
	char* result = all_tests();
	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	while (1);
}

#endif
