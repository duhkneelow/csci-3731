all: main

main.o: main.cc angle.h
	g++ -c main.cc
	
angle.o: angle.cc angle.h
	g++ -c angle.cc
	
main:	angle.o main.o
	g++ -o main main.o angle.o