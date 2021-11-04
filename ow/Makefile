CFLAGS += -Wall -Wextra

all: test_ow
	./test_ow

test_ow: ow.o test_ow.o
	$(CC) test_ow.o ow.o -o test_ow

ow.o: ow.c ow.h

test_ow.o: test_ow.c ow.h
