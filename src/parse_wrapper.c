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

/* Define `_GNU_SOURCE` for functions like `strndupa` */
#define  _GNU_SOURCE
#include "parse_wrapper.h"
#include "password.h"
#include "utility.h"
#include <ctype.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function implementation for printing all credentials */
void print_all_credential(const char *number_row)
{
	/* Get the path to the password file */
	char *filename = file_name(NAMEFILE);
	FILE *file_password, *file_row;
	read_file(&file_password, filename);
	read_file(&file_row, filename);

	long line = 0;

	/* Get the number of rows (credentials) */
	size_t row = count_row(file_row);
	/* Allocate memory for an array of credential structs */
	credential_t *credential = all(file_password, row);

	/* Check if the input argument is a number */
	if (isdigit(number_row[0]))
		/* Convert the string to a long integer (line number) */
		line = strtol(number_row, NULL, 10);
	else
		perror("Error input is not number");

	/* Adjust the number of rows to print based on the input (if valid) */
	if (line > 0)
		row = (size_t) line;

	puts("ID Website Username Email Password");

	for (size_t i = 0; i < row; i++) {
		printf("%zu %s %s %s %s\n", i + 1, credential[i].website,
		       credential[i].username, credential[i].email,
		       credential[i].password);
	}

	for (size_t i = 0; i < row; i++) {
		free(credential[i].website);
		free(credential[i].username);
		free(credential[i].email);
		free(credential[i].password);
	}

	free(credential);
	free(filename);
	close_file(&file_row);
	close_file(&file_password);
}

/* Function implementation for create credential */
void create_credential(const char *new_credential)
{
	/* Initialize a new credential struct */
	credential_t credential = { 0, 0, 0, 0 };
	const char *delimiters = " ";
	char *token;
	char *copy_credential;

	/* Check if the input string is empty or only contains whitespace */
	if (new_credential[0] == ' ' || new_credential[0] == '\0') {
		perror("Error input, string is empty");
		exit(EXIT_FAILURE);
	}

	/* Create a copy of the input string using strndupa */
	copy_credential = strndupa(new_credential, strlen(new_credential));
	if (copy_credential == NULL) {
		perror("Error allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the input string to extract website, username, email, and password */
	token = strtok(copy_credential, delimiters);
	if (token != NULL) {
		/* Allocate memory for the website field */
		credential.website = malloc(100 * sizeof(char));
		if (credential.website)
			/* Copy the token (website) into the allocated memory */
			strncpy(credential.website, token,
				strlen(token) + 1);
		else {
			perror("Error allocation failed");
			exit(EXIT_FAILURE);
		}
	} else {
		perror("Error input token, string is empty");
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, delimiters);
	if (token != NULL) {
		/* Allocate memory for the username field */
		credential.username = malloc(100 * sizeof(char));
		if (credential.username)
			/* Copy the token (username) into the allocated memory */
			strncpy(credential.username, token,
				strlen(token) + 1);
		else {
			perror("Error allocation failed");
			free(credential.website);
			exit(EXIT_FAILURE);
		}
	} else {
		perror("Error input token, string is empty");
		free(credential.website);
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, delimiters);
	if (token != NULL) {
		/* Allocate memory for the email field */
		credential.email = malloc(100 * sizeof(char));
		if (credential.email)
			/* Copy the token (email) into the allocated memory */
			strncpy(credential.email, token,
				strlen(token) + 1);
		else {
			perror("Error allocation failed");
			free(credential.username);
			free(credential.website);
			exit(EXIT_FAILURE);
		}
	} else {
		perror("Error input token, string is empty");
		free(credential.username);
		free(credential.website);
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, delimiters);
	if (token != NULL) {
		/* Allocate memory for the password field */
		credential.password = malloc(100 * sizeof(char));
		if (credential.password)
			/* Copy the token (password) into the allocated memory */
			strncpy(credential.password, token,
				strlen(token) + 1);
		else {
			perror("Error allocation failed");
			free(credential.username);
			free(credential.website);
			free(credential.email);
			exit(EXIT_FAILURE);
		}
	} else {
		perror("Error input token, string is empty");
		free(credential.username);
		free(credential.website);
		free(credential.email);
		exit(EXIT_FAILURE);
	}

	/* Get the filename for the password file */
	char *filename = file_name(NAMEFILE);

	/* Open the password file */
	FILE *file;
	open_file(&file, filename);

	/* Create the new credential in the file */
	create(file, credential);
	close_file(&file);
	free(filename);
}

/* Function implementation for search all credentials */
void search_credential(const char *search_key)
{
	/* Get the path to the password file */
	char *filename = file_name(NAMEFILE);
	FILE *file_password, *file_row;
	read_file(&file_password, filename);
	read_file(&file_row, filename);

	/* Get the number of rows (credentials) */
	size_t row = count_row(file_row);
	/* Allocate memory for an array of credential structs */
	credential_t *credential = all(file_password, row);

	/* Search for the specified search key in the credentials */
	int *result = search(credential, row, search_key);

	/* Iterate over the results and print matching credentials */
	for (int i = 0; i < (int) row; i++) {
		if (result[i] != -1)
			printf
			    ("Website: %s Username: %s Email: %s Password: %s\n",
			     credential[result[i]].website,
			     credential[result[i]].username,
			     credential[result[i]].email,
			     credential[result[i]].password);
	}

	for (size_t i = 0; i < row; i++) {
		free(credential[i].website);
		free(credential[i].username);
		free(credential[i].email);
		free(credential[i].password);
	}

	free(result);
	free(credential);
	free(filename);
	close_file(&file_row);
	close_file(&file_password);
}

/* Function implementation for delete all credential */
void delete_credential(const char *input_row)
{
	char *filename = file_name(NAMEFILE);
	FILE *file_password;
	open_file(&file_password, filename);

	char *tmp_filename = file_name(TMPNAMEFILE);
	FILE *file_tmp;
	/* Create a new temporary file */
	create_file(&file_tmp, tmp_filename);

	/* Initialize a line counter */
	int line = 0;

	/* Check if the input argument is a number */
	if (isdigit(input_row[0])) {
		/* Convert the input row to an integer */
		line = atoi(input_row);
		/* Rewind the password file pointer to the beginning */
		rewind(file_password);
		/* Delete the specified line from the password file and write
		   the remaining lines to the temporary file */
		delete(file_password, file_tmp, line);
		/* Remove the original password file */
		if (remove_file(filename) == 0) {
			/* Rename the temporary file to the original filename */
			if (rename_file(tmp_filename, filename) != 0)
				perror("Error rename file");
		} else
			perror("Error delete file");
	} else
		perror("Error input is not number");

	close_file(&file_password);
	close_file(&file_tmp);
	free(filename);
	free(tmp_filename);
}
