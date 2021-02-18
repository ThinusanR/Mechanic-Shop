#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Truck : virtual public Vehicle
{
	public:
		Truck(string="",string="",string="",int=0,int=0,int=0);
		
		string toString();
		int getAxle();
	private:
		int axle;

};
#endif