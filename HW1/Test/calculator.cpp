Fraction.cpp                                                                                        0000664 0001750 0001750 00000006272 13044201326 013163  0                                                                                                    ustar   jagveer                         jagveer                                                                                                                                                                                                                //Jagveer Singh
//ID 914003737
//Fraction.cpp

#include <iostream>
#include <stdexcept>
#include "Fraction.h"

using namespace std;

Fraction::Fraction()
: numerator(0), denominator(1)
{
	//Empty constructor
}

Fraction::Fraction(int a, int b)
: numerator(a), denominator(b)
{
	//Creates a new Fraction object with the given parameters
	//Check for zro denminator
	if (b==0)
		throw invalid_argument("denominator is zero");
	//Simplify
	Fraction::simplifyFraction(a, b);
	numerator = a;
	denominator = b;	
}


int Fraction::getNum() const
{
	return numerator;
}

int Fraction::getDen() const
{
	return denominator;
}

Fraction& Fraction::operator= (const Fraction& answerFraction)
{
	this->numerator = answerFraction.numerator;
	this->denominator= answerFraction.denominator;
	return *this;
}


void Fraction::simplifyFraction(Fraction& unreducedForm)
{
	int n1 = unreducedForm.numerator;
	int n2 = unreducedForm.denominator;
	int gcd, temp;

  	while ( n2 != 0 )
  	{
    	temp = n2;
    	n2 = n1%n2; 
    	n1 = temp; 
  	} 
  	gcd = n1; 
  	  	
  	unreducedForm.numerator = unreducedForm.numerator/gcd;
  	unreducedForm.denominator = unreducedForm.denominator/gcd;
  	
  	if(unreducedForm.denominator<0&&unreducedForm.numerator>0)
  	{
  		unreducedForm.denominator = -1*unreducedForm.denominator;
  		unreducedForm.numerator = -1*unreducedForm.numerator;
  	}
  	
}

void Fraction::simplifyFraction(int& a, int& b)
{
	
	int n1 = a;
	int n2 = b;
	int gcd, temp;
	
  	while ( n2 != 0 )
  	{
    	temp = n2;
    	n2 = n1%n2; 
    	n1 = temp; 
  	} 
  	gcd = n1; 
  	  	
  	a = a/gcd;
  	b = b/gcd;
  	
  	if(b<0&&a>0)
  	{
  		b = -1*b;
  		a = -1*a;
  	}
	
}



//NON Member Functions: Input and Output Stream

ostream& operator<<(std::ostream& os, Fraction& myFraction)
{
	//Simplify
	myFraction.simplifyFraction(myFraction);
	//Print whole numbers
	if (myFraction.denominator == 1)
	{
		cout<<myFraction.numerator;
		return os;
	}
	//Print ratios
	else
	{
		cout<<myFraction.numerator<<"/"<<myFraction.denominator;
		return os;
	}
}

istream& operator>>(std::istream& is, Fraction& myFraction)
{
	//Gather input
	cin >> myFraction.numerator;
	is.ignore (100, '/');
	int tempDenominator;
	cin >> tempDenominator;
	if (tempDenominator!=0)
		myFraction.denominator = tempDenominator;
	else
		throw invalid_argument("denominator is zero");
	myFraction.simplifyFraction(myFraction);	
	return is;
	
}


Fraction operator+ (const Fraction& fractionOne, const Fraction& fractionTwo) 
{
	int newDenominator, newNumerator;
	newDenominator = fractionOne.denominator * fractionTwo.denominator;
	newNumerator =  fractionOne.numerator * fractionTwo.denominator + fractionTwo.numerator * fractionOne.denominator;
	Fraction sumFraction(newNumerator, newDenominator);
	sumFraction.simplifyFraction(sumFraction);
	return sumFraction;
	
}

Fraction operator- (const Fraction& fractionOne, const Fraction& fractionTwo)
{
	int newDenominator, newNumerator;
	newDenominator = fractionOne.denominator * fractionTwo.denominator;
	newNumerator =  fractionOne.numerator * fractionTwo.denominator - fractionTwo.numerator * fractionOne.denominator;
	Fraction diffFraction(newNumerator, newDenominator);
	diffFraction.simplifyFraction(diffFraction);
	return diffFraction;
}










                                                                                                                                                                                                                                                                                                                                      Fraction.h                                                                                          0000664 0001750 0001750 00000002023 13044177352 012631  0                                                                                                    ustar   jagveer                         jagveer                                                                                                                                                                                                                //Jagveer Singh 
//ID 914003737
//Fraction.h

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include<iostream>

class Fraction
{
//Overloaded insertion operators
friend std::ostream& operator<<(std::ostream&, Fraction&);
friend std::istream& operator>>(std::istream&, Fraction&);
friend Fraction operator+ (const Fraction&, const Fraction&);
friend Fraction operator- (const Fraction&, const Fraction&);

public:
	Fraction();																	//Empty Constructor
	Fraction(int, int);															//Constructor
	Fraction& operator= (const Fraction&);										//Overloaded = operator
	int getNum() const;															//Return numerator
	int getDen() const;															//Return denominator
	void simplifyFraction(Fraction&);											//Euclid's method
	static void simplifyFraction(int& a, int& b);										//Euclid's method overloaded
	
//Private members
private:
	int numerator;																//numerator member
	int denominator;															//denominator member
};



#endif




/* Notes

operators '+', '-' and '='

*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             Makefile                                                                                            0000664 0001750 0001750 00000000776 13044231027 012356  0                                                                                                    ustar   jagveer                         jagveer                                                                                                                                                                                                                #Jagveer Singh
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  