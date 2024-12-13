/* test.h
 *
 * Copyright (C) 2022-2024 Ivan Guerreschi.
 *
 * This file is part of cpwd.
 *
 * cpwd is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * cpwd is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with cpwd.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef TEST_H
#define TEST_H

#include <stdio.h>

/* defines a constant for the test file name. */
#define NAMEFILETEST "/.passwordtest"

/* ANSI color codes */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* Test assertion macro */
#define ASSERT_TEST(test_name, function_call) \
	do { \
		int result = (function_call); \
		printf("Test %s: %s%s%s\n", \
		test_name, \
		(result == 0) ? ANSI_COLOR_GREEN "PASSED" : ANSI_COLOR_RED "FAILED", \
		ANSI_COLOR_RESET, \
		(result == 0) ? "" : " (Error code: 1)"); \
	} while (0)

/* Wrapper test function */
int all_password_test(void);
int delete_password_test(void);
int new_password_test(void);
int remove_password_test_file(void);
int search_password_test(void);

#endif /* TEST_H */
