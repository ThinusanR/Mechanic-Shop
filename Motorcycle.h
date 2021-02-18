#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Motorcycle : virtual public Vehicle
{
	public:
		Motorcycle(string="",string="",string="",int=0,int=0,bool=0);
		string toString();
		bool getSideCar();
	private:
		bool sideCar;
};
#endif
