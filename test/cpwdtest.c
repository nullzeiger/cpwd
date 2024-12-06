/* cpwdtest.c 
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

#include "test.h"

/* Test all wrapper function */
int
main (void)
{
  int test = 1;
  
  if (!new_password_test ())
    test = 0;

  if (!all_password_test ())
    test = 0;
    
  if (!search_password_test ())
    test = 0;

  if (!delete_password_test ())
    test = 0;
  
  ASSERT_TEST ("create new password", new_password_test ());
  ASSERT_TEST ("all password", all_password_test ());
  ASSERT_TEST ("search password", search_password_test ());
  ASSERT_TEST ("delete password", delete_password_test ());

  if (!remove_password_test_file ())
    test = 0;

  return test;
}
