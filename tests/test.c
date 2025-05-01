/* test.c
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

#include "test.h"
#include "../src/password.h"
#include "../src/utility.h"
#include <string.h>
#include <stdlib.h>

/* Test all_password function */
int
all_password_test ()
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILE` constant */
  char *file = file_name (NAMEFILE);

  FILE *file_password, *file_row;
  open_file (&file_password, file);
  read_file (&file_row, file);

  /* Count the number of rows (credentials) in the test file */
  size_t row = count_row (file_row);

  /* Allocate memory for an array of credential structs to hold the data */
  struct credential *credential = all (file_password, row);

  /* Check if the first credential in the array matches the expected data */
  if (strncmp (credential[0].website, "webpippo", 8) == 0 &&
      strncmp (credential[0].username, "pippo", 5) == 0 &&
      strncmp (credential[0].email, "pippo@topolandia.com", 20) == 0
      && strncmp (credential[0].password, "1234", 4) == 0)
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

/* Test delete_password function */
int
delete_password_test ()
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILE` constant */
  char *file = file_name (NAMEFILE);

  /* Declare file pointers for the password file and a temporary file (not used here) */
  FILE *file_password, *file_row;

  open_file (&file_password, file);
  read_file (&file_row, file);

  /* Count the number of rows (credentials) in the test file */
  size_t row = count_row (file_row);

  /* Allocate memory for an array of credential structs to hold the data */
  struct credential *credential = all (file_password, row);

  /* Check if the first credential in the array matches the expected data */
  if (strncmp (credential[0].website, "webpippo", 8) == 0 &&
      strncmp (credential[0].username, "pippo", 5) == 0 &&
      strncmp (credential[0].email, "pippo@topolandia.com", 20) == 0
      && strncmp (credential[0].password, "1234", 4) == 0)
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

/* Test new_password function */
int
new_password_test ()
{
  /* Initialize a variable to store the test result (0 for success) */
  int value = 0;

  /* Get the test file name from the `NAMEFILE` constant */
  char *file = file_name (NAMEFILE);

  /* Declare a file pointer for the password file */
  FILE *file_password;

  /* Open the test file in write mode for creating a new credential */
  create_file (&file_password, file);

  /* Define a credential struct to hold the test data */
  struct credential credential;

  /* Allocate memory for the website field of the credential struct */
  credential.website = malloc (50 * sizeof (char));
  if (credential.website)
    {
      /* If memory allocation is successful, copy the test website data */
      strcpy (credential.website, "webpippo");
    }
  else
    {
      /* If memory allocation fails, print an error message and exit */
      perror ("Error allocation memory");
      exit (1);
    }

  /* Allocate memory for the username field of the credential struct */
  credential.username = malloc (50 * sizeof (char));
  if (credential.username)
    {
      strcpy (credential.username, "pippo");
    }
  else
    {
      perror ("Error allocation memory");
      free (credential.website);
      exit (1);
    }

  /* Allocate memory and copy data for email and password fields */
  credential.email = malloc (50 * sizeof (char));
  if (credential.email)
    {
      strcpy (credential.email, "pippo@topolandia.com");
    }
  else
    {
      perror ("Error allocation memory");
      free (credential.website);
      free (credential.username);
      exit (1);
    }

  credential.password = malloc (50 * sizeof (char));
  if (credential.password)
    {
      strcpy (credential.password, "1234");
    }
  else
    {
      perror ("Error allocation memory");
      free (credential.website);
      free (credential.username);
      free (credential.email);
      exit (1);
    }

  /* Check if the created credential data matches the expected values */
  if ((strncmp (credential.website, "webpippo", 8) == 0) &&
      (strncmp (credential.username, "pippo", 5) == 0) &&
      (strncmp (credential.email, "pippo@topolandia.com", 20) == 0) &&
      (strncmp (credential.password, "1234", 4) == 0))
    {
      /* Set test result to success (0) if data matches */
      value = 0;
    }
  else
    {
      /* If any field doesn't match, keep the test result as fail (1) */
      value = 1;
    }

  /* Write the new credential to the file */
  create (file_password, credential);

  close_file (&file_password);

  free (file);

  /* Return the test result (0 for success, 1 for fail) */
  return value;
}

/* Remove tmp file for test */
int
remove_password_test_file ()
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILE` constant */
  char *file = file_name (NAMEFILE);

  /* Attempt to remove the test file using the `remove_file` function
     Check if removal was successful (return value 0) */
  if (remove_file (file) == 0)
    {
      free (file);
      /* Return 0 to indicate successful test (file removed) */
      value = 0;
    }
  else
    {
      free (file);
      /* Return 1 to indicate failed test (file removal failed) */
      value = 1;
    }

  return value;
}

/* Test search_password function */
int
search_password_test ()
{
  /* Initialize a variable to store the test result (1 for fail) */
  int value = 1;

  /* Get the test file name from the `NAMEFILE` constant */
  char *file = file_name (NAMEFILE);

  /* Declare file pointers for the password file and a temporary file (not used here) */
  FILE *file_password, *file_row;

  open_file (&file_password, file);
  read_file (&file_row, file);

  /* Count the number of rows (credentials) in the test file */
  size_t row = count_row (file_row);

  /* Read all credentials from the test file and store them in an array */
  struct credential *credential = all (file_password, row);

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

  free (credential[0].website);
  free (credential[0].username);
  free (credential[0].email);
  free (credential[0].password);

  free (credential);
  free (result);
  free (file);

  /* Return the test result (0 for success, 1 for fail) */
  return value;
}
