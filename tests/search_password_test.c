/* search_password_test.c

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

#include <stdlib.h>
#include "include/utility_test.h"
#include "password.h"
#include "utility.h"

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

  const char *key = "webpippo";

  int *result = search (credential, row, key);

  if (result[0] != -1)
    value = 0;
  else
    value = 1;

  free (result);

  return value;
}
