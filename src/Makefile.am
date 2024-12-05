# src/Makefile.am
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
# along with this cpwd.  If not, see <http://www.gnu.org/licenses/>.

include $(top_srcdir)/flymake.mk

AM_CFLAGS = -Wall -Wextra -Wdouble-promotion -Wformat-security \
	-Wformat-signedness -Winit-self -Wshift-overflow=2 \
	-Wswitch-default -Wstrict-overflow=4 \
	-Warith-conversion -Wduplicated-branches \
	-Wduplicated-cond -Wshadow -Wcast-qual \
	-Wconversion -Wdate-time -Wstrict-prototypes \
	-Wmissing-prototypes -Winvalid-pch -Wredundant-decls \
	-Wformat-nonliteral -ggdb

nobase_include_HEADERS = info.h utility.h password.h parse_wrapper.h parse_input.h 
bin_PROGRAMS = cpwd
cpwd_SOURCES = cpwd.c info.c parse_input.c parse_wrapper.c password.c utility.c