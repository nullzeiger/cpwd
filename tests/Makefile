# tests/Makefile
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

# Path to source directory
SRC_DIR = ../src
OBJ_DIR = ../obj
BIN_DIR = ../bin

# Source files needed for tests
SRC_OBJS = $(OBJ_DIR)/password.o $(OBJ_DIR)/utility.o

SRCS = tests.c cpwdtest.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/cpwdtest

all: $(TARGET)

$(TARGET): $(OBJS) $(SRC_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
