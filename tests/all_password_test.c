/* all_password_test.c

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

#include "include/utility_test.h"
#include "password.h"
#include "utility.h"
#include <stdlib.h>
#include <string.h>

int
main (void)
{
  int value = 1;

  const char *file = file_name (NAMEFILETEST);

  FILE *file_password, *file_row;
  open_file (&file_password, file);
  open_file (&file_row, file);

  size_t row = count_row (file_row);
  credential_t *credential = all (file_password, row);

  if ((strncmp (credential[0].website, "webpippo", 8) == 0)
      && (strncmp (credential[0].username, "pippo", 5) == 0)
      && (strncmp (credential[0].email, "pippo@topolandia.com", 20) == 0)
      && (strncmp (credential[0].password, "1234", 4) == 0))
    value = 0;
  else
    value = 1;

  close_file (&file_password);
  close_file (&file_row);

  free (credential[0].website);
  credential[0].website = NULL;
  free (credential[0].username);
  credential[0].username = NULL;
  free (credential[0].email);
  credential[0].email = NULL;
  free (credential[0].password);
  credential[0].password = NULL;

  free (credential);
  credential = NULL;

  return value;
}
