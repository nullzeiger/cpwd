/* password.c
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

#include "password.h"
#include "utility.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Opens a file in append and read+write mode.
 * If opening fails, prints an error message and exits. */
void
open_file (FILE **file, const char *filename)
{
  if ((*file = fopen (filename, "a+")) == NULL)
    {
      perror ("Error open file");
       exit (EXIT_FAILURE);
    }
}

/* Creates a file in write+read mode.
 * If creation fails, prints an error message and exits. */
void
create_file (FILE **file, const char *filename)
{
  if ((*file = fopen (filename, "w+")) == NULL)
    {
      perror ("Error create file");
       exit (EXIT_FAILURE);
    }
}

/* Opens a file in read+write mode.
 * If opening fails, prints an error message and exits. */
void
read_file (FILE **file, const char *filename)
{
  if ((*file = fopen (filename, "r+")) == NULL)
    {
      perror ("Error read file");
       exit (EXIT_FAILURE);
    }
}

/* Closes a file.
 * If closing fails, prints an error message and exits. */
void
close_file (FILE **file)
{
  if (fclose (*file) != 0)
    {
      perror ("Error close file");
      exit (EXIT_FAILURE);
    }
}

/* Counts the number of rows (lines) in a file. */
size_t
count_row (FILE *file)
{
  int c;
  size_t count = 0;

  /* Read characters until EOF */
  for (c = getc (file); c != EOF; c = getc (file))
    /* Increment count for each newline character */
    if (c == '\n')
      count++;

  return count;
}

/* Allocates memory for an array of credential structs and reads data from a file.
 * If memory allocation fails, prints an error message and exits.
 * Reads website, username, email, and password from each line. */
struct credential *
all (FILE *file, size_t row)
{
  struct credential *credential =
    calloc (row + 1, sizeof (struct credential));

  if (!credential)
    {
      perror ("Error allocation failed");
      exit (EXIT_FAILURE);
    }

  /* Allocate memory for website, username, email, and password for each credential */
  for (size_t i = 0; i < row; i++)
    {
      credential[i].website = malloc (100 * sizeof (char));
      if (!credential[i].website)
	{
	  perror ("Error allocation failed");
	  exit (EXIT_FAILURE);
	}

      credential[i].email = malloc (100 * sizeof (char));
      if (!credential[i].email)
	{
	  perror ("Error allocation failed");
	  exit (EXIT_FAILURE);
	}

      credential[i].username = malloc (100 * sizeof (char));
      if (!credential[i].username)
	{
	  perror ("Error allocation failed");
	  exit (EXIT_FAILURE);
	}

      credential[i].password = malloc (100 * sizeof (char));
      if (!credential[i].password)
	{
	  perror ("Error allocation failed");
	  exit (EXIT_FAILURE);
	}
    }

  /* Read data from the file */
  int i = 0;
  int res = 0;

  while (1)
    {
      res = fscanf (file, "%s", credential[i].website);
      if (res != 1)
	break;

      res = fscanf (file, "%s", credential[i].username);
      if (res != 1)
	break;

      res = fscanf (file, "%s", credential[i].email);
      if (res != 1)
	break;

      res = fscanf (file, "%s", credential[i].password);
      if (res != 1)
	{
	  perror ("Error read file .password");
	  exit (EXIT_FAILURE);
	}

      i++;
    }

  return credential;
}

/* Creates a new credential in the file.
 * Allocates memory for a new string, concatenates the website, username, email, and password,
 * and writes the new credential to the file.
 * Frees allocated memory. */
void
create (FILE *file, struct credential credential)
{
  /* Buffer to hold temporary data during string concatenation */
  char buffer[BUFSIZ];
  /* Allocate initial memory for the new credential string */
  char *new_credential = calloc (1, 1);

  if (!new_credential)
    {
      perror ("Error allocation failed");
      exit (EXIT_FAILURE);
    }
  else
    {
      /* Concatenate website, username, email, and password with spaces */
      strcpy (buffer, credential.website);
      new_credential =
	realloc (new_credential,
		 strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
      else
	strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.username);
      new_credential =
	realloc (new_credential,
		 strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
	{
	  perror ("Error allocation failed");
	  exit (EXIT_FAILURE);
	}
      else
	strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.email);
      new_credential =
	realloc (new_credential,
		 strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
      else
	strcat (new_credential, strcat (buffer, " "));

      strcpy (buffer, credential.password);
      new_credential =
	realloc (new_credential,
		 strlen (new_credential) + 2 + strlen (buffer));
      if (!new_credential)
	{
	  fprintf (stderr, "Error allocation failed");
	  exit (EXIT_FAILURE);
	}
      else
	strcat (new_credential, strcat (buffer, " "));

      /* Write the formatted new credential string to the file followed by a newline */
      fprintf (file, "%s\n", new_credential);
    }

  free (credential.website);
  free (credential.username);
  free (credential.email);
  free (credential.password);
  free (new_credential);
}

/* Searches for a given key (website, username, email, or password) in the credentials.
 * Returns an array of indices where the key was found. */
int *
search (struct credential *credential, size_t row, const char *key)
{
  /* Allocates memory for an array of integers to store search results. */
  int *results = malloc (row * sizeof (int));
  if (results == NULL)
    {
      exit (1);
    }

  int i = 0;
  for (i = 0; i < (int) row; i++)
    {
      /* Check if the key matches any of the fields in the current credential */
      if (strcmp (credential[i].website, key) == 0 ||
	  strcmp (credential[i].username, key) == 0 ||
	  strcmp (credential[i].email, key) == 0 ||
	  strcmp (credential[i].password, key) == 0)
	{
	  /* Set the index to the current position if a match is found */
	  results[i] = i;
	}
      else
	/* Set the index to -1 if no match is found */
	results[i] = -1;
    }

  return results;
}

/* Deletes a credential from the file by copying all lines except the specified
 * line to a temporary file. */
void
delete (FILE *file, FILE *tmp_file, const int line)
{
  /* Buffer to store a line of text from the file */
  int buffer_capacity = 1024;
  char buffer[buffer_capacity];
  int count = 1;

  /* Read lines from the original file */
  while ((fgets (buffer, buffer_capacity, file)) != NULL)
    {
      /* If the current line is not the one to be deleted, write it to the
         temporary file */
      if (line != count)
	fputs (buffer, tmp_file);

      count++;
    }
}
