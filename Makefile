CXX = g++
CC = gcc

all:	apdorojimas

test:	all
	./apdorojimas

clean:
	rm -f *.o apdorojimas