# man/Makefile.am
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

man_MANS = cpwd.1

cpwd.1: $(top_srcdir)/src/cpwd.c
	$(HELP2MAN) -p cpwd --name="Simple Command-Line Password Management Tool" \
		$(top_srcdir)/src/cpwd$(EXEEXT) -o $@

EXTRA_DIST = $(man_MANS)
MAINTAINERCLEANFILES = cpwd.1
