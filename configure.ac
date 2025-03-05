# configure.ac
#
# Copyright (C) 2025 Ivan Guerreschi.
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

dnl Minimum Autoconf version required.
AC_PREREQ([2.71])

dnl Package information.
AC_INIT([cpwd],
	[1.6.1],
	[ivan.guerreschi.dev@gmail.com])

dnl Safety checks.
AC_CONFIG_SRCDIR([src/cpwd.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

dnl Initialize automake.
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])

dnl Generate config.h.
AC_CONFIG_HEADERS([config.h])

dnl Checks for  programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MKDIR_P

dnl Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strtol])

dnl Checks for header files.
AC_CHECK_HEADERS([getopt.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

dnl Include the Autoconf macros from -fanalyzer flag.
m4_include([m4/ax_gcc_analyzer.m4])
dnl Checks for -fanalyzer flag.
AX_CHECK_GCC_ANALYZER

dnl Checks for help2man.
AS_IF([test $cross_compiling = no], [
  AM_MISSING_PROG([HELP2MAN], [help2man])
], [
  HELP2MAN=:
])

dnl Configure Makefile outputs.
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 tests/Makefile
 doc/Makefile
 man/Makefile
])


dnl Display configuration.
AC_MSG_NOTICE([
  ${PACKAGE_NAME} version ${PACKAGE_VERSION}
  Compiler: '${CC}'
])

AC_OUTPUT
