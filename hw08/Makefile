all: main

Log.o: Log.cc Log.h
	g++ -c Log.cc
	
Angle.o: Angle.cc Angle.h
	g++ -c Angle.cc

Population.o: Population.cc Population.h Fish.h
	g++ -c Population.cc

Fish.o: Fish.cc Angle.h Fish.h
	g++ -c Fish.cc

main.o: main.cc Fish.h Log.h Population.h
	g++ -c main.cc
	
main:	Angle.o Fish.o Log.o Population.o main.o
	g++ -o main main.o Angle.o Fish.o Log.o Population.o