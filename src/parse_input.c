/* parse_input.c
 *
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
#include "parse_wrapper.h"
#include "info.h"
#include "password.h"
#include "utility.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* This function is responsible for parsing the command-line
 * arguments provided to the program. */
void
parsing (int argc, char **argv)
{
  int opt;

  /* Define short option string */
  const char *short_opts = "a::c:d:s:vlh";

  /* Define long options array */
  static struct option long_options[] = {
    {"all", optional_argument, 0, 'a'},
    {"create", required_argument, 0, 'c'},
    {"delete", required_argument, 0, 'd'},
    {"help", no_argument, 0, 'h'},
    {"license", no_argument, 0, 'l'},
    {"search", required_argument, 0, 's'},
    {"version", no_argument, 0, 'v'},
    {0, 0, 0, 0}
  };

  while (1)
    {
      /* Get the next option using getopt_long */
      opt = getopt_long (argc, argv, short_opts, long_options, 0);

      /* If there are no more options, break the loop */
      if (opt == -1)
	break;

      /* Switch statement to handle different options */
      switch (opt)
	{
	case 'a':
	  optarg ? print_all_credential (optarg) : print_all_credential ("0");
	  break;
	case 'c':
	  create_credential (optarg);
	  break;
	case 'd':
	  delete_credential (optarg);
	  break;
	case 'h':
	  printf ("%s\n%s\n%s\n", help (), license (), bugreport ());
	  break;
	case 'l':
	  printf ("%s\n", license ());
	  break;
	case 's':
	  search_credential (optarg);
	  break;
	case 'v':
	  printf ("%s\n", package ());
	  break;
	case '?':
	  printf ("%s\n", help ());
	  break;
	default:
	  abort ();
	}
    }
}
