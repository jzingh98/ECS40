//Jagveer Singh 
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
