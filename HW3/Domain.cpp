//Jagveer Singh
//ID 914003737
//Domain.cpp

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Domain.h"
using namespace std;


Domain::Domain(int sx, int sy)
:size_x(sx), size_y(sy)
{
	//Constructor
}

void Domain::addShape(char type, int x, int y)
{
	//Create Shape Object
	Shape* addedShapePtr = Shape::makeShape(type, x, y);
	//Test if it fits in domain
	if(!fits(*addedShapePtr))
		{
			delete addedShapePtr;
			return;
		}
	//Test if it overlaps
	bool inClear = true;
	for (size_t i = 0; i<sList.size(); ++i)
	{
		if (addedShapePtr->overlap(*sList[i]))
			inClear = false;
	}
	if(!inClear)
	{
		delete addedShapePtr;
		return;
	}
	//Add to vector
	sList.push_back(addedShapePtr);
	
}


bool Domain::fits(const Shape &s) const
{
	int numCells = s.size();
	bool fitting = true;
	for (int i = 0; i<numCells; ++i)
	{
		if (s.getX(i)>=size_x||s.getX(i)<0)
			fitting = false;
		if (s.getY(i)>=size_y||s.getY(i)<0)
			fitting = false;
	}
	return fitting;
}

bool Domain::full(void) const
{
	int domainSize = size_x*size_y;
	int numFilled = 0;
	for (size_t i = 0; i<sList.size(); ++i)
	{
		numFilled = numFilled + sList[i]->size();
	}
	if (numFilled>=domainSize)
	{
		return true;
	}
	return false;	
}

void Domain::draw(void) const
{
	cout<<"<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>"<<endl;
	cout<<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<<endl;
	cout<<"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"<<endl;
	cout<<"<svg width=\"670\" height=\"670\" viewBox=\"0 0 650 650\""<<endl;
	cout<<"xmlns=\"http://www.w3.org/2000/svg\""<<endl;
	cout<<"xmlns:xlink=\"http://www.w3.org/1999/xlink\" >"<<endl;
	cout<<"<g transform=\"matrix(1,0,0,-1,50,650)\">"<<endl;
	cout<<"<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\""<<40*size_x<<"\" height=\""<<40*size_y<<"\"/>"<<endl;
	//Print Each Shape
	for (size_t i = 0; i<sList.size(); ++i)
	{
		sList[i]->draw();
	}
	cout<<"</g>"<<endl;
	cout<<"</svg>"<<endl;
	
}












