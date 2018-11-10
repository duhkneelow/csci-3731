all: main

Log.o: Log.cc Log.h
	g++ -c Log.cc

Exception.o: Exception.cc Exception.h
	g++ -c Exception.cc


Drunk.o: Drunk.cc Drunk.h
	g++ -c Drunk.cc

Flip.o: Flip.cc Angle.h Flip.h
	g++ -c Flip.cc

Fish.o: Fish.cc Angle.h Fish.h
	g++ -c Fish.cc

main.o: main.cc Fish.h Log.h
	g++ -c main.cc
	
main:	Fish.o Log.o Exception.o Drunk.o Flip.o main.o
	g++ -o main main.o Fish.o Log.o Exception.o Drunk.o Flip.o