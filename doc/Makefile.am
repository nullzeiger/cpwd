# doc/Makefile.am
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
# along with this cpwd.  If not, see <http://www.gnu.org/licenses/>.

# Create info page from textinfo file.
info_TEXINFOS = cpwd.texi

# Create man from help2man
# Set cpwd 
AX_HELP2MAN_PREFIX_BIN = $(top_srcdir)/src
if HAVE_HELP2MAN
man1_MANS = $(ax_help2man_MANS)
@AX_HELP2MAN_RULES@
EXTRA_DIST = $(man1_MANS)
endif

MAINTAINERCLEANFILES = cpwd.info man1_MANS
