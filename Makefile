CXX = g++
CC = gcc

all:	main.o galutinis.o print.o read.o
	g++ main.o galutinis.o print.o read.o -o apdorojimas

main.o: main.cpp main.h
	g++ -c main.cpp

galutinis.o: galutinis.cpp
	g++ -c galutinis.cpp

print.o: print.cpp
	g++ -c print.cpp

read.o: read.cpp
	g++ -c read.cpp

test:	all
	./apdorojimas

clean:
	rm -f *.o apdorojimas