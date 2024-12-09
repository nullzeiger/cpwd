/* cpwd.c
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

#include "parse_input.h"
#include <stdlib.h>
#include <stdio.h>

/* The main function is the entry point of the program.
 *
 * This function takes two arguments:
 *   - argc: An integer representing the number of arguments passed to the program
 *          (including the program name itself).
 *   - argv: An array of character pointers, where each element points to a string
 *          argument passed to the program.
 *
 * The function calls the `parsing` function
 * to handle parsing the command-line arguments.
 *
 * Finally, the function returns `EXIT_SUCCESS` to indicate successful program execution. */
int
main (int argc, char **argv)
{
  puts ("cpwd  Copyright (C) 2022-2024  Ivan Guerreschi\n"
    "This program comes with ABSOLUTELY NO WARRANTY;\n"
    "This is free software, and you are welcome to redistribute it\n"
    "under certain conditions; type `cpwd -l' for details.\n");
  parsing (argc, argv);

  return EXIT_SUCCESS;
}
