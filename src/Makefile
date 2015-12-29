



CC=gcc
CFLAGS=-c -Wall -Werror


all:stack
stack:stack.o
	$(CC) stack.o -o stack
stack.o:stack.c
	$(CC) $(CFLAGS) stack.c
clean:
	rm -rf *o stack
