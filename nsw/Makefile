CFLAGS += -Wall -Wextra

all: test_nsw
	./test_nsw

test_nsw: nsw.o test_nsw.o
	$(CC) test_nsw.o nsw.o -o test_nsw

nsw.o: nsw.c nsw.h

test_nsw.o: test_nsw.c nsw.h
