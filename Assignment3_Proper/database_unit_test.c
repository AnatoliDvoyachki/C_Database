#include "database.h"
#include "minunit.h"
#include <stdio.h>
#include <stdbool.h>

// Unit test for some of the functions in the database.c file

#ifdef DATABASE_UNIT_TEST

// function parameter constants
const int NUMBER_OF_EXISTING_STUDENT = 253651;
const int NUMBER_OF_NOT_EXISTING_STUDENT = 729301;

const int NUMBER_OF_EXISTING_TEACHER = 829402;
const int NUMBER_OF_NOT_EXISTING_TEACHER = 432402;

const int COURSE_NUMBER_OF_STUDENT_ENROLMENT = 10;
const int NUMBER_OF_EXISTING_COURSE = 31;

const char IS_A_NUMBER_STRING[] = "Hello";
const char IS_A_NUMBER_INTEGER[] = "50";

const int NUMBER_OF_STUDENT_WITHOUT_ENROLMENTS = 754321;

int tests_run = 0;

static char* test_find_student_when_it_exists()
{
	student_t found;
	found = find_student(NUMBER_OF_EXISTING_STUDENT);
	mu_assert("student with number 253651 does not exist!", found != NULL);
}

static char* test_find_student_when_it_does_not_exist()
{
	student_t found = NULL;
	found = find_student(NUMBER_OF_NOT_EXISTING_STUDENT);
	mu_assert("student with number 253651 does not exist!", found == NULL);
}

static char* test_teacher_exists_when_true()
{
	mu_assert("test_teacher_exists_when_teacher_exists: true != true", teacher_exists(NUMBER_OF_EXISTING_TEACHER) == true);
}

static char* test_teacher_exists_when_false()
{
	mu_assert("test_teacher_exists_when_teacher_exists: true != true", teacher_exists(NUMBER_OF_NOT_EXISTING_TEACHER) ==
		false);
}

static char* test_enrolment_matches_when_true()
{
	mu_assert("test_enrolment_matches_when_true: true != true", enrolment_matches(COURSE_NUMBER_OF_STUDENT_ENROLMENT,
		NUMBER_OF_EXISTING_STUDENT) == true);
}

static char* test_enrolment_matches_when_false()
{
	mu_assert("test_enrolment_matches_when_false: false != false", enrolment_matches(COURSE_NUMBER_OF_STUDENT_ENROLMENT,
		NUMBER_OF_NOT_EXISTING_STUDENT) == false);
}

static char* test_assignment_matches_when_true()
{
	mu_assert("test_assignment_matches_when_true: true != true", assignment_matches(NUMBER_OF_EXISTING_TEACHER,
		NUMBER_OF_EXISTING_COURSE) == true);
}

static char* test_assignment_matches_when_false()
{
	mu_assert("test_assignment_matches_when_false: false != false", assignment_matches(NUMBER_OF_NOT_EXISTING_TEACHER,
		NUMBER_OF_EXISTING_COURSE) == false);
}

static char* test_is_number_with_string()
{
	mu_assert("test_is_number_with_string: false != false", is_number(IS_A_NUMBER_STRING) == false);
}

static char* test_is_number_with_integer()
{
	mu_assert("test_is_number_with_integer: true != true", is_number(IS_A_NUMBER_INTEGER) == true);
}

static char* test_has_enrolments_when_true()
{
	mu_assert("test_has_enrolments_when_true: true!= true", has_enrolments(NUMBER_OF_EXISTING_STUDENT) == true);
}

static char* test_has_enrolments_when_false()
{
	mu_assert("test_has_enrolments_when_false: false!= false", has_enrolments(NUMBER_OF_STUDENT_WITHOUT_ENROLMENTS) ==
		false);
}

static char* test_remove_student_when_successful()
{
	mu_assert("test_remove_student_when_successful: 1 != 1", remove_student(NUMBER_OF_EXISTING_STUDENT) == 1);
}


static char* test_remove_student_when_unsuccessful()
{
	mu_assert("test_remove_student_when_unsuccessful: 0 != 0", remove_student(NUMBER_OF_NOT_EXISTING_STUDENT) == 0);
}

static char* all_tests()
{
	mu_run_test(test_find_student_when_it_exists);
	mu_run_test(test_find_student_when_it_does_not_exist);
	mu_run_test(test_teacher_exists_when_true);
	mu_run_test(test_teacher_exists_when_false);
	mu_run_test(test_enrolment_matches_when_true);
	mu_run_test(test_enrolment_matches_when_false);
	mu_run_test(test_assignment_matches_when_true);
	mu_run_test(test_assignment_matches_when_false);
	mu_run_test(test_is_number_with_string);
	mu_run_test(test_is_number_with_integer);
	mu_run_test(test_has_enrolments_when_true);
	mu_run_test(test_has_enrolments_when_false);
	mu_run_test(test_remove_student_when_successful);
	mu_run_test(test_remove_student_when_unsuccessful);
}

int main()
{
	populate_database(); // to get the data
	char* result = all_tests();
	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("\nALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	while (1);
}

#endif
