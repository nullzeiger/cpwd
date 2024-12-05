/* parse_wrapper.h
 *
 * Copyright (C) 2022-2024 Ivan Guerreschi.
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

#ifndef PARSE_WRAPPER_H
#define PARSE_WRAPPER_H

/* This function likely takes a `const char *input_row` argument which might be
 * a number representing the number of credentials to print or some other input
 * relevant to displaying all credentials. */
void print_all_credential (const char *input_row);

/* This function likely takes a `const char *new_credential` argument which
 * contains the information for a new credential to be created. */
void create_credential (const char *new_credential);

/* This function likely takes a `const char *search_key` argument which
 * specifies the key to search for within the stored credentials. */
void search_credential (const char *search_key);

/* This function likely takes a `const char *input_row` argument which might be
 *  an identifier for the credential to be deleted. */
void delete_credential (const char *input_row);

#endif /* PARSE_WRAPPER_H */
