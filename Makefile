# Root Makefile
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

.PHONY: all clean help src tests install runtest uninstall

all: 
	mkdir -p bin obj
	$(MAKE) src
	$(MAKE) tests

src:
	$(MAKE) -C src

tests: src
	$(MAKE) -C tests

runtest: tests
	./bin/cpwdtest

install:
	$(MAKE) -C src install

uninstall:
	$(MAKE) -C src uninstall

help:
	@echo "CPWD Project Makefile Commands:"
	@echo "  all       - Build entire project (default)"
	@echo "  src       - Build source files"
	@echo "  tests     - Build source test files"
	@echo "  runtest   - Run tests"
	@echo "  install   - Install executable to ~/.local/bin"
	@echo "  uninstall - Remove executable from ~/.local/bin"
	@echo "  clean     - Remove all build artifacts"
	@echo ""
	@echo "Usage examples:"
	@echo "  make              # Build entire project"
	@echo "  make install      # Install program"
	@echo "  make clean        # Clean build artifacts"

clean:
	$(MAKE) -C src clean
	$(MAKE) -C tests clean
	rm -rf bin obj
