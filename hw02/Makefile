all: main

main.o: main.cc squared.h
	g++ -c main.cc
	
squared.o: squared.cc squared.h
	g++ -c squared.cc
	
main:	squared.o main.o
	g++ -o main main.o squared.o