/* password.h

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

#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdio.h>

/* Define a structure named credential_t to store
   website, username, email, and password */
typedef struct {
	char *website;
	char *username;
	char *email;
	char *password;
} credential_t;

/* Opens the file specified by `filename`. 
   Assigns the file pointer to the `file` pointer. */
void open_file(FILE ** file, const char *filename);

/*  Creates a new file specified by `filename`.
    Assigns the file pointer to the `file` pointer. */
void create_file(FILE ** file, const char *filename);

/* Reads credentials from the file specified by `filename`.
   Assigns the file pointer to the `file` pointer. */
void read_file(FILE ** file, const char *filename);

/* Function to close a file.
   Closes the file pointed to by `file`. */
void close_file(FILE ** file);

/* Function to count the number of rows (credentials) in a file.
   Counts the number of lines in the file.
   Returns the count as a `size_t` value. */
size_t count_row(FILE * file);

/* Function to allocate memory for and populate an array of credentials
   Reads all credentials from the file and stores them in an array of `credential_t` structures.
   Allocates memory for the array and returns a pointer to it.*/
credential_t *all(FILE * file, size_t row);

/* Function to create a new credential entry in a file
   Appends a new credential to the end of the file.
   The `credential` argument contains the website, username, email, and password to be added*/
void create(FILE * file, credential_t credential);

/* Function to search for a credential based on a key (e.g., username)
   Searches for a credential in the array of credentials based on the given `key`.
   Returns an array of indices of matching credentials.*/
int *search(credential_t * credential, size_t row, const char *key);

/* Function to delete a credential entry from a file
   Deletes the credential at the specified `line` number.
   Creates a temporary file, copies all credentials except the one to be deleted,
   and then renames the temporary file to the original file name. */
void delete(FILE * file, FILE * tmp_file, const int line);

#endif				/* PASSWORD_H */
