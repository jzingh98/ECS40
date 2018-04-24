//Jagveer Singh
//Fraction.h

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>

class Fraction
{
//Overloaded insertion operators
friend std::ostream& operator<<(std::ostream&, const Fraction&);
friend std::istream& operator>>(std::istream&, Fraction&);
//Public members
public:
    Fraction();
	//Fraction(int, int);															//Constructor
	//Fraction operator+(const Fraction&, const Fraction&);						//Overloaded + operator
	//Fraction operator-(const Fraction&, const Fraction&);						//Overloaded - operator
	//Fraction& operator=(Fraction&, const Fraction&);							//Overloaded = operator
	int getNum();																//Return numerator
	int getDen();																//Return denominator

//Private members
private:
	int numerator;																//numerator member
	int denominator;															//denominator member
};



#endif

