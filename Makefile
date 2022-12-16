TARGET	= main
CFLAGS	= -g -c -D_POSIX_C_SOURCE -D_GNU_SOURCE -Iinclude
CLFAGS += -std=c99 -Wimplicit-function-declaration -Werror
CFLAGS +=

LDFLAGS =

.PHONY: all
all: main

main: main.o queue.o
	gcc $^ -o $@

%.o: %.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(TARGET) *.o *.dSYM