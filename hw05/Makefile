all: main

main.o: main.cc print.h
	g++ -c main.cc
	
print.o: print.cc print.h
	 g++ -c print.cc
	
main:	print.o main.o
	g++ -o main print.o main.o