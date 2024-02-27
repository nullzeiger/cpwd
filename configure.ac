dnl configure.ac
dnl
dnl Copyright (C) 2022-2024 Ivan Guerreschi.
dnl
dnl This file is part of cpwd.
dnl
dnl cpwd is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl
dnl cpwd is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl
dnl You should have received a copy of the GNU General Public License
dnl along with cwd.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.69])
AC_INIT([cpwd], [1.4], [ivan.guerreschi.dev@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([src/main.c])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADER_STDBOOL
AC_CHECK_FUNCS([memset strcspn strerror strndup])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_TYPE_SIZE_T

# Check gnu11 flag
AX_CHECK_COMPILE_FLAG(-std=gnu11,
	[AX_CHECK_COMPILE_FLAG([-std=gnu11])],
	[echo "C compiler cannot compile gnu11 code"])

dnl Check -fanalyze flag
AX_CHECK_COMPILE_FLAG(-fanalyzer,
	[AX_APPEND_FLAG([-fanalyzer])],
	[echo "C compiler doesn't support Static Analyzer Options (-fanalyzer)"])

AC_CONFIG_FILES([Makefile
	lib/Makefile
	src/Makefile
	tests/Makefile])
AC_OUTPUT
