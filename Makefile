# Makefile
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

CC = gcc
CFLAGS = -O2 -g -ggdb -Wall -Wextra -Werror \
	-Wformat=2 -Wunused -march=native \
	-Wconversion -Wmissing-prototypes \
	-Wstrict-prototypes -Wcast-qual \
	-Wnull-dereference -Wduplicated-cond \
	-fstack-protector-strong -pie -fPIE \
	-D_FORTIFY_SOURCE=2 -fno-omit-frame-pointer

TARGET = cpwd
TARGET_TEST = cpwdtest

SRCS = cpwd.c info.c parse_input.c parse_wrapper.c password.c utility.c
SRCS_TEST = cpwdtest.c test.c password.c utility.c
OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
HEADERS = info.h parse_input.h parse_wrapper.h password.h utility.h
HEADERS_TEST = test.h password.h utility.h

all: $(TARGET) $(TARGET_TEST)
test: $(TARGET_TEST)
bin: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET_TEST): $(OBJS_TEST)
	$(CC) $(OBJS_TEST) -o $(TARGET_TEST)

%.o: %.c $(HEADERS_TEST)
	$(CC) $(CFLAGS) -c $< -o $@
	
runtest:
	./cpwdtest

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f $(OBJS_TEST) $(TARGET_TEST)

prefix = ~/.local/
install: $(TARGET)
	mkdir -p $(prefix)/bin
	install -d $(prefix)/bin
	install -m 755 $(TARGET)$(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/$(TARGET)
	
help:
	@echo "CPWD Project Makefile Commands:"
	@echo "  all       - Build entire project (default)"
	@echo "  bin       - Build source cpwd"
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

.PHONY: all bin test runtest clean install uninstall
