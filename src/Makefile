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
# along with cpwd.  If not, see <http://www.gnu.org/licenses/>.

CC = gcc
CFLAGS = -O2 -march=native -g -ggdb \
         -Wall -Wextra -Werror \
         -Wformat=2 -Wunused \
         -Wconversion -Wmissing-prototypes \
         -Wstrict-prototypes -Wcast-qual \
         -Wnull-dereference -Wduplicated-cond \
         -fstack-protector-strong -pie -fPIE \
         -D_FORTIFY_SOURCE=2 -fno-omit-frame-pointer
LDFLAGS = -Wl,-z,defs -Wl,-z,now -Wl,-z,relro

SRCS = info.c cpwd.c parse_input.c parse_wrapper.c password.c utility.c
OBJS = $(SRCS:%.c=../obj/%.o)
TARGET = ../bin/cpwd
INSTALL_DIR = $(HOME)/.local/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

../obj/%.o: %.c
	@mkdir -p ../obj
	$(CC) $(CFLAGS) -c $< -o $@

install: $(TARGET)
	@mkdir -p $(INSTALL_DIR)
	install -m 755 $(TARGET) $(INSTALL_DIR)/cpwd

uninstall:
	rm -f $(INSTALL_DIR)/cpwd

clean:
	rm -f $(OBJS) $(TARGET)
