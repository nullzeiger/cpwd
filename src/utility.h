/* utility.h

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

#ifndef UTILITY_H
#define UTILITY_H

/* Defines the constant NAMEFILE with the path to the password file */
#define NAMEFILE  "/.password"
/* Defines the constant TMPNAMEFILE with the path to the temporary password file */
#define TMPNAMEFILE "/.passwordtmp"

/* This function likely takes a `const char *file_password` argument
   which might be a directory path or filename. It returns a `char *` pointer to a string
   containing the full path to the password file. The function might perform some processing
   on the input argument to construct the complete path (e.g., prepend a leading directory path). */
char *file_name(const char *file_password);

/* This function likely takes a `const char *file` argument which is the path to a file.
   It returns an integer indicating the success or failure of deleting the specified file.
   A return value of 0 typically indicates success, while non-zero values might indicate errors. */
int remove_file(const char *file);

/* This function likely takes two arguments:
     - `const char *old_file`: The path to the source file to be renamed.
     - `const char *new_file`: The path to the destination file where the source file will be renamed to.
   It returns an integer indicating the success or failure of renaming the file.
   A return value of 0 typically indicates success, while non-zero values might indicate errors.  */
int rename_file(const char *old_file, const char *new_file);

#endif				/* UTILITY_H */
