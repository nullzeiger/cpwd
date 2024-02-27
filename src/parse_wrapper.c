/* parse_wrapper.c

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

#include "include/parse_wrapper.h"
#include "password.h"
#include "utility.h"
#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 100

void
print_all_credential (const char *number_row)
{
  const char *filename = file_name (NAMEFILE);
  FILE *file_password, *file_row;
  open_file (&file_password, filename);
  open_file (&file_row, filename);

  long line = 0;

  size_t row = count_row (file_row);
  credential_t *credential = all (file_password, row);

  if (isdigit (number_row[0]))
    line = strtol (number_row, NULL, 10);
  else
    fprintf (stderr, "Error input is not number");

  if (line > 0)
    row = (size_t) line;

  puts ("ID Website Username Email Password");

  for (size_t i = 0; i < row; i++)
    {
      printf ("%zu %s %s %s %s\n", i + 1, credential[i].website,
	      credential[i].username, credential[i].email,
	      credential[i].password);
    }

  for (size_t i = 0; i < row; i++)
    {
      free (credential[i].website);
      free (credential[i].username);
      free (credential[i].email);
      free (credential[i].password);
    }

  free (credential);
  credential = NULL;
  close_file (&file_row);
  close_file (&file_password);
}

void
create_credential (const char *new_credential)
{
  credential_t credential = { 0, 0, 0, 0 };
  const char *delimiters = " ";
  char *token;
  char *copy_credential;

  if (new_credential[0] == ' ' || new_credential[0] == '\0')
    {
      puts ("Error input, string is empty");
      exit (EXIT_FAILURE);
    }

  copy_credential = strndup (new_credential, strlen (new_credential));

  token = strtok (copy_credential, delimiters);
  if (token[0] != '\0')
    {
      credential.website = malloc (100 * sizeof (char));
      if (credential.website)
	strncpy (credential.website, token, strlen (token) + 1);
      else
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
    }
  else
    {
      fprintf (stderr, "Error input token, string is empty");
      exit (EXIT_FAILURE);
    }

  token = strtok (NULL, delimiters);
  if (token[0] != '\0')
    {
      credential.username = malloc (100 * sizeof (char));
      if (credential.username)
	strncpy (credential.username, token, strlen (token) + 1);
      else
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
    }
  else
    {
      fprintf (stderr, "Error input token, string is empty");
      exit (EXIT_FAILURE);
    }

  token = strtok (NULL, delimiters);
  if (token[0] != '\0')
    {
      credential.email = malloc (100 * sizeof (char));
      if (credential.email)
	strncpy (credential.email, token, strlen (token) + 1);
      else
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
    }
  else
    {
      fprintf (stderr, "Error input token, string is empty");
      exit (EXIT_FAILURE);
    }

  token = strtok (NULL, delimiters);
  if (token[0] != '\0')
    {
      credential.password = malloc (100 * sizeof (char));
      if (credential.password)
	strncpy (credential.password, token, strlen (token) + 1);
      else
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
    }
  else
    {
      fprintf (stderr, "Error input token, string is empty");
      exit (EXIT_FAILURE);
    }

  const char *filename = file_name (NAMEFILE);
  FILE *file;
  open_file (&file, filename);
  create (file, credential);
  close_file (&file);
  free (copy_credential);
}

void
search_credential (const char *search_key)
{
  const char *filename = file_name (NAMEFILE);
  FILE *file_password, *file_row;
  open_file (&file_password, filename);
  open_file (&file_row, filename);

  size_t row = count_row (file_row);
  credential_t *credential = all (file_password, row);

  int *result = search (credential, row, search_key);

  for (int i = 0; i < (int) row; i++)
    {
      if (result[i] != -1)
	printf ("Website: %s Username: %s Email: %s Password: %s\n",
		credential[result[i]].website, credential[result[i]].username,
		credential[result[i]].email, credential[result[i]].password);
    }

  free (result);

  for (size_t i = 0; i < row; i++)
    {
      free (credential[i].website);
      free (credential[i].username);
      free (credential[i].email);
      free (credential[i].password);
    }

  free (credential);
  credential = NULL;
  close_file (&file_row);
  close_file (&file_password);
}

void
delete_credential (const char *input_row)
{
  const char *filename = file_name (NAMEFILE);
  const char *tmp_filename = NAMEFILETMP;
  FILE *file_password, *file_tmp;
  open_file (&file_password, filename);
  open_file (&file_tmp, tmp_filename);
  int line = 0;

  if (isdigit (input_row[0]))
    {
      line = atoi (input_row);
      rewind (file_password);
      delete (file_password, file_tmp, line);
      if (remove_file (filename) == 0)
	rename (tmp_filename, filename);
      else
	fprintf (stderr, "Error delete file");
    }
  else
    fprintf (stderr, "Error input is not number");

  close_file (&file_password);
  close_file (&file_tmp);
}
