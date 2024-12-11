# configure.ac
#
# Copyright (C) 2022-2024 Ivan Guerreschi.
#
# This file is part of cpwd.
#
# cpwd is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cpwd is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cpwd.  If not, see <http://www.gnu.org/licenses/>.

AC-PREREQ([2.69])
AC_INIT([cpwd], [1.6.1], [ivan.guerreschi.dev@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/cpwd.c])
AC_PROG_CC

AM_MISSING_PROG(HELP2MAN, help2man)

AC_CONFIG_FILES([
 Makefile
 src/Makefile
 test/Makefile
 doc/Makefile
 man/Makefile
])

AC_OUTPUT
