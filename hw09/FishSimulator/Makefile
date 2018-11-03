all: main

Log.o: Log.cc Log.h
	g++ -c Log.cc
	
Angle.o: Angle.cc Angle.h
	g++ -c Angle.cc

Exception.o: Exception.cc Exception.h
	g++ -c Exception.cc

Population.o: Population.cc Population.h Fish.h Exception.h
	g++ -c Population.cc

Drunk.o: Drunk.cc Angle.h Drunk.h
	g++ -c Drunk.cc

Flip.o: Flip.cc Angle.h Flip.h
	g++ -c Flip.cc

Fish.o: Fish.cc Angle.h Fish.h
	g++ -c Fish.cc

main.o: main.cc Fish.h Log.h Population.h
	g++ -c main.cc
	
main:	Angle.o Fish.o Log.o Population.o Exception.o Drunk.o Flip.o main.o
	g++ -o main main.o Angle.o Fish.o Log.o Population.o Exception.o Drunk.o Flip.o