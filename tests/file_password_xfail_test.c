/* file_password_xfail_test.c

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

#include "utility_test.h"
#include "utility.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main (void)
{
  char *file = file_name (NAMEFILETEST);

  if (strcmp (file, ".password") == 0)
    {
      free (file);
      return 0;
    }
  else
    {
      free (file);
      return 1;
    }
}
