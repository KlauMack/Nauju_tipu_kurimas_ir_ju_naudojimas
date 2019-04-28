CXX = g++
CC = gcc

all:	main.o galutinis.o print.o read.o generate.o compareByLetter.o
	g++ main.o galutinis.o print.o read.o generate.o compareByLetter.o -o apdorojimas

main.o: main.cpp main.h
	g++ -c main.cpp

galutinis.o: galutinis.cpp
	g++ -c galutinis.cpp

print.o: print.cpp
	g++ -c print.cpp

read.o: read.cpp
	g++ -c read.cpp

generate.o: generate.cpp
	g++ -c generate.cpp

compareByLetter.o: compareByLetter.cpp
	g++ -c compareByLetter.cpp

test:	all
	./apdorojimas

clean:
	rm -f *.o apdorojimas