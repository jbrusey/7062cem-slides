CFLAGS += -Wall -Wextra

all: test_ewma
	./test_ewma

test_ewma: ewma.o test_ewma.o

ewma.o: ewma.c ewma.h

test_ewma.o: test_ewma.c ewma.h
