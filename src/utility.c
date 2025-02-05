/* utility.c
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

#include "utility.h"
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/* This function get complete file path for the .password file.
 * The function returns the allocated memory containing the full path to the filename. */
char *
file_name (const char *file_password)
{
  /* Get the user's home directory */
  char *home_dir = getenv ("HOME");
  /* If HOME environment variable is not set,
   *  try to get it from the password database */
  if (home_dir == NULL)
    {
      struct passwd *pwd = getpwuid (getuid ());
      if (pwd == NULL)
	{
	  perror ("Error get HOME variable");
	  return NULL;
	}
      home_dir = pwd->pw_dir;
    }

  /* Calculate the total length needed for the filename,
   * including the null terminator */
  size_t len = strlen (home_dir) + strlen (file_password) + 1;

  /* Allocate memory for the filename string */
  char *file = malloc (len);
  if (file == NULL)
    {
      perror ("Error allocation failed");
      return NULL;
    }

  /* Format the filename by concatenating the home directory
   * and the file password */
  snprintf (file, len, "%s%s", home_dir, file_password);

  return file;
}

/* This function remove file */
int
remove_file (const char *file)
{
  /* Attempt to remove the file specified by the `file` argument */
  if (remove (file) == 0)
    return 0;
  else
    {
      perror ("Error remove file");
      return -1;
    }
}

/* This function rename file */
int
rename_file (const char *old_file, const char *new_file)
{
  /* Attempt to rename the file from `old_file` to `new_file` */
  if (rename (old_file, new_file) == 0)
    return 0;
  else
    {
      perror ("Error rename file");
      return -1;
    }
}
