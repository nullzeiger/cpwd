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

# Minimum Autoconf version required.
AC_PREREQ([2.71])

# Package information.
AC_INIT([cpwd],
	[1.6.1],
	[ivan.guerreschi.dev@gmail.com])

# Safety checks.
AC_CONFIG_SRCDIR([src/cpwd.c])
AC_CONFIG_MACRO_DIR([m4])

# Initialize automake.
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])

# Generate config.h.
AC_CONFIG_HEADERS([config.h])

# Checks for  programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MKDIR_P

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strtol])

# Checks for header files.
AC_CHECK_HEADERS([getopt.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

dnl Checks for -fanalyzer flag.
m4_include([m4/m4_ax_check_compile_flag.m4])
AX_CHECK_COMPILE_FLAG(
	-fanalyzer,
	[CFLAGS="$CFLAGS -fanalyzer"],
	[AC_MSG_WARN(["Compiler does not support -fanalyzer"])]
)

# Checks for help2man.
AS_IF([test $cross_compiling = no], [
  AM_MISSING_PROG([HELP2MAN], [help2man])],
  [HELP2MAN=:]
)

# Configure Makefile outputs.
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 tests/Makefile
 doc/Makefile
 man/Makefile
])


# Display configuration.
AC_MSG_NOTICE([
  ${PACKAGE_NAME} version ${PACKAGE_VERSION}
  Compiler: '${CC}'])

AC_OUTPUT
