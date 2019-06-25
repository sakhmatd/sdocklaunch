CC = gcc

CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wno-unused-variable
CFLAGS += -Wcast-align
CFLAGS += -Wswitch-default
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef

CFLAGS += -D_POSIX_C_SOURCE=200809L

CFLAGS += `pkg-config --cflags gtk+-2.0`
LIBS   += `pkg-config --libs gtk+-2.0`

PREFIX = usr/local

PROJECT = sdocklaunch

all:
	$(CC) $(CFLAGS) *.c -o $(PROJECT) $(LIBS)

memcheck:
	valgrind --leak-check=yes ./$(PROJECT)

memcheck_v:
	valgrind --leak-check=yes -v ./$(PROJECT)

clean:
	rm $(PROJECT)

install:
	cp $(PROJECT) $(DESTDIR)/$(PREFIX)/bin/$(PROJECT)

uninstall:
	rm $(DESTDIR)/$(PREFIX)/bin/$(PROJECT)
