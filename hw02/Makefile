all: main

main.o: main.cc factorial.h
	g++ -c main.cc
	
factorial.o: factorial.cc factorial.h
	g++ -c factorial.cc
	
main:	factorial.o main.o
	g++ -o main main.o factorial.o