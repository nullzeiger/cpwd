# Makefile.am
#
# Copyright (C) 2022-2024 Ivan Guerreschi
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

include $(top_srcdir)/flymake.mk

TESTS = file_password_test file_password_xfail_test new_password_test \
	all_password_test search_password_test delete_password_test \
	remove_file_password_test
XFAIL_TESTS = file_password_xfail_test
check_PROGRAMS = $(TESTS)
noinst_HEADERS = utility_test.h

file_password_test_SOURCES = file_password_test.c
file_password_test_CFLAGS = -I $(top_srcdir)/lib
file_password_test_LDADD = $(top_builddir)/lib/libpassword.a

file_password_xfail_test_SOURCES = file_password_xfail_test.c 
file_password_xfail_test_CFLAGS = -I $(top_srcdir)/lib
file_password_xfail_test_LDADD = $(top_builddir)/lib/libpassword.a

new_password_test_SOURCES = new_password_test.c 
new_password_test_CFLAGS = -I $(top_srcdir)/lib
new_password_test_LDADD = $(top_builddir)/lib/libpassword.a

all_password_test_SOURCES = all_password_test.c
all_password_test_CFLAGS = -I $(top_srcdir)/lib
all_password_test_LDADD = $(top_builddir)/lib/libpassword.a

search_password_test_SOURCES = search_password_test.c 
search_password_test_CFLAGS = -I $(top_srcdir)/lib
search_password_test_LDADD = $(top_builddir)/lib/libpassword.a

delete_password_test_SOURCES = delete_password_test.c 
delete_password_test_CFLAGS = -I $(top_srcdir)/lib
delete_password_test_LDADD = $(top_builddir)/lib/libpassword.a

remove_file_password_test_SOURCES = remove_file_password_test.c 
remove_file_password_test_CFLAGS = -I $(top_srcdir)/lib
remove_file_password_test_LDADD = $(top_builddir)/lib/libpassword.a
