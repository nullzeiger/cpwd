/* info.c

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

#include "info.h"
#include <string.h>


const char *
version (void)
{
  return VERSION;
}

const char *
package (void)
{
  return PACKAGE_STRING;
}

const char *
bugreport (void)
{
  return PACKAGE_BUGREPORT;
}

const char *
license (void)
{
  return "cpwd is free software: you can redistribute it and/or "
    "modify\n"
    "it under the terms of the GNU General Public License as published "
    "by\n"
    "the Free Software Foundation, either version 3 of the License, or\n"
    "(at your option) any later version.\n\n"
    "cpwd is distributed in the hope that it will be useful,\n"
    "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    "GNU General Public License for more details.\n\n"
    "You should have received a copy of the GNU General Public License\n"
    "along with cpwd.  If not, see " "<https://www.gnu.org/licenses/>.\n";
}

const char *
help (void)
{

  return "password-cli-manager options\n"
    "Options:\n"
    "  -a --all All credential\n"
    "  -aNUM --all=NUM Number of credentials entered in the NUM input\n"
    "  -c\"WEBSITE USERNAME EMAIL PASSWORD\" Create credential\n"
    "  --create=\"WEB USERNAME EMAIL PASSWORD\" Create credential\n"
    "  -dNUM  --delete=NUM Delete credential\n"
    "  -h Help\n"
    "  -sWORD --search=WORD Search credential\n" "  -v Program version\n";
}
