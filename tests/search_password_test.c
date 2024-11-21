/* search_password_test.c

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

#include <stdlib.h>
#include "utility_test.h"
#include "password.h"
#include "utility.h"

/* The main function for the search_password_test program.

   This program tests the `search` function from the `password.c` file
   by searching for a specific website (key) within credentials read
   from a test file. The program checks if the search result is valid
   (not -1) and sets the test result accordingly.

   Returns:
     0 if the test passes, 1 if the test fails. */
int
main (void)
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  /* Declare file pointers for the password file and a temporary file (not used here) */
  FILE *file_password, *file_row;

  open_file (&file_password, file);
  read_file (&file_row, file);

  /* Count the number of rows (credentials) in the test file */
  size_t row = count_row (file_row);

  /* Read all credentials from the test file and store them in an array */
  credential_t *credential = all (file_password, row);

  /* Define the website (key) to search for */
  const char *key = "webpippo";

  /* Call the `search` function to find the index of the matching website (or -1 if not found) */
  int *result = search (credential, row, key);

  /* Check if the search result is valid (not -1, indicating a match) */
  if (result[0] != -1)
    {
      /* Set test result to success (0) if a match is found */
      value = 0;
    }
  else
    {
      /* Keep test result as fail (1) if no match is found */
      value = 1;
    }

  free (result);
  free (file);

  /* Return the test result (0 for success, 1 for fail) */
  return value;
}
