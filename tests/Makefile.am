# test/Makefile.am
#
# Copyright (C) 2025 Ivan Guerreschi
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

# Include custom make rules for flymake.
include $(top_srcdir)/flymake.mk

# Compiler warnings and debug flags.
AM_CFLAGS = \
	-Wall \
	-Wextra \
	-Wdouble-promotion \
	-Wformat-security \
	-Wformat-signedness \
	-Winit-self \
	-Wshift-overflow=2 \
	-Wswitch-default \
	-Wstrict-overflow=4 \
	-Warith-conversion\
	-Wduplicated-branches \
	-Wduplicated-cond \
	-Wshadow -Wcast-qual \
	-Wconversion \
	-Wdate-time \
	-Wstrict-prototypes \
	-Wmissing-prototypes \
	-Winvalid-pch \
	-Wredundant-decls \
	-Wformat-nonliteral \
	-ggdb \
	-fsanitize=address \
	$(NULL)

AM_LDFLAGS= -fsanitize=address

# Headers
noinst_HEADERS = test.h

# Program definition.
TESTS = new_password all_password search_password delete_password #remove_file 
check_PROGRAMS = $(TESTS)

all_password_SOURCES = all_password.c test.c $(top_srcdir)/src/password.c $(top_srcdir)/src/utility.c
delete_password_SOURCES = delete_password.c test.c $(top_srcdir)/src/password.c $(top_srcdir)/src/utility.c
new_password_SOURCES = new_password.c test.c $(top_srcdir)/src/password.c $(top_srcdir)/src/utility.c
#remove_file_SOURCES = remove_file.c test.c $(top_srcdir)/src/password.c $(top_srcdir)/src/utility.c
search_password_SOURCES = search_password.c test.c $(top_srcdir)/src/password.c $(top_srcdir)/src/utility.c

# DejaGNU
#SUBDIRS = testsuite

AUTOMAKE_OPTIONS = dejagnu
DEJATOOL = cpwd
AM_RUNTESTFLAGS  = --tool $$tool --srcdir $$srcdir

EXTRA_DIST = cpwd.exp
