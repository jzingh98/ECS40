//Jagveer Singh
//ID 914003737
//Shape.cpp

#include <iostream>
#include <stdexcept>
#include "Shape.h"
using namespace std;

Shape::~Shape()
{
	//Remove pointers for x and y
	delete[] x;
	delete[] y;
}
//virtual char name(void) const = 0;
//virtual int size(void) const = 0;
//virtual const char* color(void) const = 0;
int Shape::getX(int i) const
{
	return x[i];
}
int Shape::getY(int i) const
{
	return y[i];
}
void Shape::print(void) const
{
	cout<<name()<<" at";
	int i = 0;
	int n = size();
	for(i=0; i<n; ++i)
	{
		cout<<" ("<<x[i]<<","<<y[i]<<")";
	}
	cout<<endl;
	
}
void Shape::draw(void) const
{
	int i = 0;
	int n = size();
	for(i=0; i<n; ++i)
	{
		cout<<"<rect fill=\""<<color()<<"\" stroke=\"black\" ";
		cout<<"x=\""<<x[i]*40<<"\" y=\""<<y[i]*40<<"\" width=\"40\" height=\"40\"/>";			
		cout<<endl;
	}
}
void Shape::move (int dx, int dy)
{
	int i = 0;
	int n = size();
	for(i=0; i<n; ++i)
	{
		x[i]=x[i]+dx;
		y[i]=y[i]+dy;
	}
}
bool Shape::overlap(const Shape &t) const
{
	bool conflict = false;
	int iThis = 0;
	int nThis = size();
	int iThat = 0;
	int nThat = t.size();
	for(iThis=0; iThis<nThis; ++iThis)
	{
		for(iThat=0; iThat<nThat; ++iThat)
		{
			if((x[iThis]==t.x[iThat])&&(y[iThis]==t.y[iThat]))
			{
				conflict = true;
				return conflict;
			}
		}
	}
	return conflict;
	
}
Shape* Shape::makeShape(char ch,int posx,int posy)
{
	//Validate character
	if ((ch!='O')&&(ch!='I')&&(ch!='L')&&(ch!='S')&&(ch!='X')&&(ch!='U'))
	{
		throw invalid_argument("invalid type");
	}
	//Declare shape pointer
	Shape* shapePtr;
	//Create instance of appropriate object
	if(ch=='O')
	{
		shapePtr = new O(posx, posy);
	}
	else if(ch=='I')
	{
		shapePtr = new I(posx, posy);
	}
	else if(ch=='L')
	{
		shapePtr = new L(posx, posy);
	}
	else if(ch=='S')
	{
		shapePtr = new S(posx, posy);
	}
	else if(ch=='X')
	{
		shapePtr = new X(posx, posy);
	}
	else if(ch=='U')
	{
		shapePtr = new U(posx, posy);
	}
	//Default return
	return shapePtr; 
}




//DERIVED CLASS: O
O::O(int posx, int posy)
{
	//Initialize member arrays
	x = new int[1]();
	y = new int[1]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
}
char O::name(void) const
{
	return 'O';
}
int O::size(void) const
{
	return 1;
}
const char* O::color(void) const
{
	return "cyan";
}


//DERIVED CLASS: I
I::I(int posx, int posy)
{
	//Initialize member arrays
	x = new int[2]();
	y = new int[2]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
	//Set additional positions
	x[1] = posx;
	y[1] = posy+1;
}
char I::name(void) const
{
	return 'I';
}
int I::size(void) const
{
	return 2;
}
const char* I::color(void) const
{
	return "yellow";
}


//DERIVED CLASS: L
L::L(int posx, int posy)
{
	//Initialize member arrays
	x = new int[3]();
	y = new int[3]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
	//Set additional positions
	x[1] = posx+1;
	y[1] = posy;
	x[2] = posx;
	y[2] = posy+1;
}
char L::name(void) const
{
	return 'L';
}
int L::size(void) const
{
	return 3;
}
const char* L::color(void) const
{
	return "purple";
}


//DERIVED CLASS: S
S::S(int posx, int posy)
{
	//Initialize member arrays
	x = new int[4]();
	y = new int[4]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
	//Set additional positions
	x[1] = posx+1;
	y[1] = posy;
	x[2] = posx+1;
	y[2] = posy+1;
	x[3] = posx+2;
	y[3] = posy+1;
}
char S::name(void) const
{
	return 'S';
}
int S::size(void) const
{
	return 4;
}
const char* S::color(void) const
{
	return "blue";
}


//DERIVED CLASS: X
X::X(int posx, int posy)
{
	//Initialize member arrays
	x = new int[5]();
	y = new int[5]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
	//Set additional positions
	x[1] = posx-1;
	y[1] = posy+1;
	x[2] = posx;
	y[2] = posy+1;
	x[3] = posx+1;
	y[3] = posy+1;
	x[4] = posx;
	y[4] = posy+2;
}
char X::name(void) const
{
	return 'X';
}
int X::size(void) const
{
	return 5;
}
const char* X::color(void) const
{
	return "orange";
}


//DERIVED CLASS: U
U::U(int posx, int posy)
{
	//Initialize member arrays
	x = new int[7]();
	y = new int[7]();
	//Set initial position
	x[0] = posx;
	y[0] = posy;
	//Set additional positions
	x[1] = posx+1;
	y[1] = posy;
	x[2] = posx+2;
	y[2] = posy;
	x[3] = posx;
	y[3] = posy+1;
	x[4] = posx+2;
	y[4] = posy+1;
	x[5] = posx;
	y[5] = posy+2;
	x[6] = posx+2;
	y[6] = posy+2;
}
char U::name(void) const
{
	return 'U';
}
int U::size(void) const
{
	return 7;
}
const char* U::color(void) const
{
	return "red";
}






