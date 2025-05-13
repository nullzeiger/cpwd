# Makefile.am
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

# Subdirectories to build
SUBDIRS = \
	src \
	tests \
	testsuite \
	doc \
	$(NULL)

# Documentation files
dist_doc_DATA = \
    README \
    AUTHORS \
    ChangeLog \
    NEWS \
    $(NULL)

# Additional files to include in distribution
EXTRA_DIST = \
    bootstrap \
    $(NULL)

# Files and directories to remove with 'make maintainer-clean'
MAINTAINERCLEANFILES = \
    Makefile.in \
    aclocal.m4 \
    build-aux/compile \
    build-aux/config.guess \
    build-aux/config.sub \
    build-aux/depcomp \
    build-aux/install-sh \
    build-aux/missing \
    config.h.in \
    config.h.in~ \
    configure \
    m4/libtool.m4 \
    m4/ltoptions.m4 \
    m4/ltsugar.m4 \
    m4/ltversion.m4 \
    m4/lt~obsolete.m4 \
    $(NULL)

# Clean generated files
CLEANFILES = \
    *~ \
    *.bak \
    *.log \
    *.scan \
    .deps \
    $(NULL)

# Custom targets
.PHONY: ChangeLog

ChangeLog:
	$(AM_V_GEN)if test -d "$(top_srcdir)/.git"; then \
	    git log --stat --name-only --date=short --abbrev-commit > $@; \
	fi

# Generate ChangeLog before distribution
dist-hook: ChangeLog
