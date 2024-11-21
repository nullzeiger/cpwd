/* all_password_test.c

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
#include "password.h"
#include "utility.h"
#include <stdlib.h>
#include <string.h>

/* The main function for the all_password_test program.

   This program tests the `all` function from the `password.c` file
   by reading credentials from a test file and checking if the first
   credential matches specific data.

   Returns:
     0 if the test passes, 1 if the test fails. */
int
main (void)
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  FILE *file_password, *file_row;
  open_file (&file_password, file);
  read_file (&file_row, file);

  /* Count the number of rows (credentials) in the test file */
  size_t row = count_row (file_row);

  /* Allocate memory for an array of credential structs to hold the data */
  credential_t *credential = all (file_password, row);

  /* Check if the first credential in the array matches the expected data */
  if (strncmp (credential[0].website, "webpippo", 8) == 0 &&
      strncmp (credential[0].username, "pippo", 5) == 0 &&
      strncmp (credential[0].email, "pippo@topolandia.com", 20) == 0 &&
      strncmp (credential[0].password, "1234", 4) == 0)
    {
      /* If all fields match, set the test result to success (0) */
      value = 0;
    }
  else
    {
      /* If any field doesn't match, keep the test result as fail (1) */
      value = 1;
    }

  close_file (&file_password);
  close_file (&file_row);

  free (credential[0].website);
  free (credential[0].username);
  free (credential[0].email);
  free (credential[0].password);
  free (credential);
  free (file);

  /* Return the test result (0 for success, 1 for fail) */
  return value;
}
