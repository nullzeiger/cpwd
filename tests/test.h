/* test.h
 *
 * Copyright (C) 2025 Ivan Guerreschi.
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

/* defines a constant for the test file name. */
#define NAMEFILETEST "/../../tmp/.passwordtest"

/* Wrapper test function */
int all_password_test (void);
int delete_password_test (void);
int new_password_test (void);
int remove_password_test_file (void);
int search_password_test (void);

#endif /* TEST */
