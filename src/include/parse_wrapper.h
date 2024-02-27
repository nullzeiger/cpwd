/* parse_wrapper.h

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

#ifndef PARSE_WRAPPER_H
#define PARSE_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

  void print_all_credential (const char *input_row);
  void create_credential (const char *new_credential);
  void search_credential (const char *search_key);
  void delete_credential (const char *input_row);

#ifdef __cplusplus
}
#endif

#endif				/* PARSE_WRAPPER_H */
