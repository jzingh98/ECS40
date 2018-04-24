#Jagveer Singh
#ID:914003737

all: calculator useFraction

calculator: calculator.o Fraction.o
	g++ -Wall calculator.o Fraction.o -o calculator

useFraction: useFraction.o Fraction.o
	g++ -Wall useFraction.o Fraction.o -o useFraction

calculator.o: calculator.cpp Fraction.h
	g++ -Wall -c calculator.cpp
   
useFraction.o: useFraction.cpp Fraction.h
	g++ -Wall -c useFraction.cpp

Fraction.o: Fraction.cpp
	g++ -Wall -c Fraction.cpp
	
clean:
	rm -f calculator useFraction calculator.o useFraction.o Fraction.o
