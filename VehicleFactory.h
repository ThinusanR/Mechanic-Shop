#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class VehicleFactory
{
	public:
		Vehicle* create(string,string,string,int,int);//car
		Vehicle* create(string,string,string,int,int,int);//truck
		Vehicle* create(string,string,string,int,int,bool);//motorcycle
	private:
		Vehicle* newVeh;
};
#endif