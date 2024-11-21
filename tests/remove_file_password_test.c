/* remove_file_password_test.c

   Copyright (C) 2022-2024 Ivan Guerreschi.

   This file is part of cpwd.

   cpwd is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   cpwd is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with cpwd.  If not, see <http://www.gnu.org/licenses/>.  */

#include "utility_test.h"
#include "utility.h"
#include <stdlib.h>

/* The main function for the remove_file_password_test program.

   This program tests the `remove_file` function (assumed to be in utility.h)
   by attempting to remove a test file specified by the `NAMEFILETEST` constant.
   The program checks the return value of `remove_file` and sets the test result
   accordingly (0 for success, 1 for failure).

   Returns:
     0 if the test passes (file removed successfully).
     1 if the test fails (file removal failed). */
int
main (void)
{
  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  /* Attempt to remove the test file using the `remove_file` function
     Check if removal was successful (return value 0) */
  if (remove_file (file) == 0)
    {
      free (file);
      /* Return 0 to indicate successful test (file removed) */
      return 0;
    }
  else
    {
      free (file);
      /* Return 1 to indicate failed test (file removal failed) */
      return 1;
    }
}
