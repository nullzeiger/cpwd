/* file_password_xfail_test.c

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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* The main function for the file_password_xfail_test program.

   This program performs a test to check if the test file name retrieved
   from the `NAMEFILETEST` constant matches a specific hardcoded value
   (".password"). It's likely intended to be an expected failure test
   (marked with "xfail" in the name) as the test file name retrieved
   might be different based on the implementation of `file_name`.

   Returns:
     0 if the test passes (file names match, which is unexpected).
     1 if the test fails (file names differ, which is expected). */
int
main (void)
{
  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  /* Compare the retrieved file name with the hardcoded ".password" string */
  if (strcmp (file, ".password") == 0)
    {
      free (file);
      /* Return 0 to indicate unexpected successful test (file names match) */
      /* This might be printed as a warning or handled differently 
         depending on the testing framework used. */
      return 0;
    }
  else
    {
      free (file);
      /* Return 1 to indicate successful test (file names differ) */
      return 1;
    }
}
