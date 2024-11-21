/* new_password_test.c

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

/* The main function for the new_password_test program.

   This program tests the `create` function from the `password.c` file
   by creating a new credential and writing it to a test file. The program then
   verifies if the written data matches the created credential.

   Returns:
   0 if the test passes, 1 if the test fails. */
int
main (void)
{
  /* Initialize a variable to store the test result (0 for success) */
  int value = 0;

  /* Get the test file name from the `NAMEFILETEST` constant */
  char *file = file_name (NAMEFILETEST);

  /* Declare a file pointer for the password file */
  FILE *file_password;

  /* Open the test file in write mode for creating a new credential */
  create_file (&file_password, file);

  /* Define a credential struct to hold the test data */
  credential_t credential;

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
