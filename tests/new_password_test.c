/* new_password_test.c

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
  int value = 0;

  const char *file = file_name (NAMEFILETEST);

  FILE *file_password;
  open_file (&file_password, file);

  credential_t credential;

  credential.website = malloc (50 * sizeof (char));
  if (credential.website)
    strcpy (credential.website, "webpippo");

  credential.username = malloc (50 * sizeof (char));
  if (credential.username)
    strcpy (credential.username, "pippo");

  credential.email = malloc (50 * sizeof (char));
  if (credential.email)
    strcpy (credential.email, "pippo@topolandia.com");

  credential.password = malloc (50 * sizeof (char));
  if (credential.password)
    strcpy (credential.password, "1234");

  if ((strncmp (credential.website, "webpippo", 8) == 0)
      && (strncmp (credential.username, "pippo", 5) == 0)
      && (strncmp (credential.email, "pippo@topolandia.com", 20) == 0)
      && (strncmp (credential.password, "1234", 4) == 0))
    value = 0;
  else
    value = 1;

  create (file_password, credential);

  close_file (&file_password);

  return value;
}
