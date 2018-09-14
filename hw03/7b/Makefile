all: main

main.o: main.cc swap.h
	g++ -c main.cc
	
swap.o: swap.cc swap.h
	g++ -c swap.cc
	
main:	swap.o main.o
	g++ -o main main.o swap.o