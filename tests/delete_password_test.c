/* delete_password_test.c

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

  int line = 1;
  char *file = file_name (NAMEFILETEST);
  const char *filetmp = "/tmp/.passwordtmp";

  FILE *file_password, *file_row, *file_tmp;
  open_file (&file_password, file);
  open_file (&file_tmp, filetmp);

  rewind (file_password);
  delete (file_password, file_tmp, line);
  remove_file (file);
  rename (filetmp, file);

  close_file (&file_password);
  close_file (&file_tmp);

  open_file (&file_row, file);

  if (count_row (file_row) == 0)
    value = 0;
  else
    value = 1;

  close_file (&file_row);

  free (file);
  
  return value;
}
