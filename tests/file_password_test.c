/* file_password_test.c

   Copyright (C) 2022-2024 Ivan Guerreschi.

   This file is part of cpwd.

   cpwd is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   cpwd is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with cpwd.  If not, see <http://www.gnu.org/licenses/>.  */

#include "utility_test.h"
#include "utility.h"
#include <stdlib.h>
#include <string.h>

/* The main function for the file_password_test program.

   This program performs a simple test to check if the test file name
   retrieved from the `NAMEFILETEST` constant matches a specific hardcoded value
   ("./.passwordtest"). It likely serves as a basic check for test file name validity.

   Returns:
     0 if the test passes (file names match).
     1 if the test fails (file names differ). */
int
main (void)
{
  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  /* Compare the retrieved file name with the hardcoded "./.passwordtest" string */
  if (strcmp (file, file_name ("/.passwordtest")) == 0)
    {
      /* Free the memory allocated for the test file name */
      free (file);

      /* Return 0 to indicate successful test (file names match) */
      return 0;
    }
  else
    {
      /* Free the memory allocated for the test file name */
      free (file);

      /* Return 1 to indicate failed test (file names don't match) */
      return 1;
    }
}
