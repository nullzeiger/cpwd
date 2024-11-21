/* parse_input.h

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

#ifndef PARSE_INPUT_H
#define PARSE_INPUT_H

/* This function likely takes two arguments:
     - `int argc`: An integer representing the number of arguments passed to the program
        (including the program name itself).
     - `char **argv`: An array of character pointers, where each element points to a string
        argument passed to the program.

   The function's purpose is to parse the command-line arguments provided to the program.
   It's likely responsible for identifying the options and arguments specified by the user
   and taking appropriate actions based on those arguments. */
void parsing (int argc, char **argv);

#endif /* PARSE_INPUT_H */
