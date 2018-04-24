#include <iostream>
#include <stdexcept>
#include "Fraction.h"

using namespace std;

int Fraction::counter = 0;

Fraction::Fraction()
: numerator(0), denominator(1)
{
	//Empty constructor
}

Fraction::Fraction(int a, int b)
: numerator(a), denominator(b)
{
	if (b==0)
		throw invalid_argument("denominator is zero");
	//Simplify
	Fraction::simplifyFraction(a, b);
	numerator = a;
	denominator = b;	
}

Fraction::~Fraction()
{
	cout<<"DEESTROYED"<<endl;
}


int Fraction::getNum() const
{
	return numerator;
}


Fraction& Fraction::operator= (const Fraction& rhs)
{
	if (&rhs==this)
		return*this;
	this->numerator = rhs.numerator;
	this->denominator= rhs.denominator;
	return *this;
}


void Fraction::simplifyFraction(Fraction& unreducedForm)
{
	int n1 = unreducedForm.numerator;
	int n2 = unreducedForm.denominator;  	
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











