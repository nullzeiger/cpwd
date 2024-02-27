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

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    char *website;
    char *username;
    char *email;
    char *password;
  } credential_t;

  void open_file (FILE ** file, const char *filename);
  void close_file (FILE ** file);
  size_t count_row (FILE * file);
  credential_t *all (FILE * file, size_t row);
  void create (FILE * file, credential_t credential);
  int *search (credential_t * credential, size_t row, const char *key);
  void delete (FILE * file, FILE * tmp_file, const int line);

#ifdef __cplusplus
}
#endif

#endif				/* PASSWORD_H */
