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
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

dnl Checks for -fanalyzer flag.
AX_CHECK_COMPILE_FLAG([-fanalyzer],
	[CFLAGS="$CFLAGS -fanalyzer"],
	[AC_MSG_WARN(["Compiler does not support -fanalyzer"])])

# Checks for help2man.
AX_PROG_HELP2MAN

# Find the 'runtest' utility provided by DejaGNU
AC_CHECK_PROG([RUNTEST_CHECK], [runtest], [yes])
AS_VAR_IF([RUNTEST_CHECK],
	["yes"],
	[],
	[AC_MSG_ERROR([DejaGNU 'runtest' program not found in PATH. Please install DejaGNU.])])

# Find the 'expect' utility required by DejaGNU/runtest
AC_CHECK_PROG([EXPECT_CHECK], [expect], [yes])
AS_VAR_IF([EXPECT_CHECK],
	["yes"],
	[],
	[AC_MSG_ERROR(['expect' program not found in PATH. Please install expect.])])

# Find the 'runtest' utility provided by DejaGNU
AC_CHECK_PROG([TEXINFO_CHECK], [makeinfo], [yes])
AS_VAR_IF([TEXINFO_CHECK],
	["yes"],
	[],
	[AC_MSG_ERROR(['texinfo' program not found in PATH. Please install texinfo.])])

AC_ARG_ENABLE([test],
[  --enable-test    Turn on testting],
[case "${enableval}" in
  yes) test=true ;;
  no)  test=false ;;
  *) AC_MSG_ERROR([bad value ${enableval} for --enable-test]) ;;
esac],[test=false])
AM_CONDITIONAL([TEST], [test x$test = xtrue])

# Configure Makefile outputs.
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 tests/Makefile
 testsuite/Makefile
 doc/Makefile
])

AC_OUTPUT
