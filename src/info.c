/* info.c
 *
 * Copyright (C) 2025 Ivan Guerreschi.
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

#include "info.h"
#include <string.h>

/* This function likely retrieves the version string from a pre-defined macro
 * or constant named `VERSION` defined elsewhere in the project. */
const char *
version (void)
{
  return VERSION;
}

/* This function likely retrieves the package name string from a pre-defined macro
 * or constant named `PACKAGE_STRING` defined elsewhere in the project. */
const char *
package (void)
{
  return PACKAGE_STRING;
}

/* This function likely retrieves the bug report address string from a pre-defined macro
 * or constant named `PACKAGE_BUGREPORT` defined elsewhere in the project. */
const char *
bugreport (void)
{
  return PACKAGE_BUGREPORT;
}

/* This function returns the full GNU General Public License. */
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

/* This function returns a string containing the help message describing
 *  the program's usage and available options. */
const char *
help (void)
{
  return "cpwd\n"
    "Options:\n"
    "  -a     --all All credential\n"
    "  -a NUM --all NUM Number of credentials entered in the NUM input\n"
    "  -c \"WEBSITE USERNAME EMAIL PASSWORD\" Create credential\n"
    "  --create \"WEB USERNAME EMAIL PASSWORD\" Create credential\n"
    "  -d NUM --delete NUM Delete credential\n"
    "  -h Help\n"
    "  -l License\n"
    "  -s KEYWORD --search KEYWORD Search credential\n"
    "  -v Program version\n";
}
