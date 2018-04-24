//Jagveer Singh
//Fraction.cpp

#include <iostream>
#include<iomanip>
#include <stdexcept>
#include "Fraction.h"

using namespace std;


Fraction::Fraction()
: numerator(1), denominator(1)
{

}




int Fraction::getNum()
{
	return numerator;
}

int Fraction::getDen()
{
	return denominator;
}






//NON Member Functions: Input and Output Stream

ostream& operator<<(std::ostream& os, const Fraction& myFraction)
{
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
	cin >> myFraction.denominator;

	//Simplify (modify the members)

	return is;

}











