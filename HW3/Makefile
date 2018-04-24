#Jagveer Singh
#ID:914003737

make: fill

fill: Domain.o Shape.o
	g++ -Wall fill.cpp Domain.o Shape.o -o fill
   
Domain.o: Domain.cpp
	g++ -Wall -c Domain.cpp Domain.h

Shape.o: Shape.cpp
	g++ -Wall -c Shape.cpp Domain.h
	
clean:
	rm -f fill Shape.o Domain.o
