#include <iostream>
using namespace std;
#include "Motorcycle.h"

Motorcycle::Motorcycle(string bike_make, string bike_model, string bike_colour, int bike_yr, int bike_mil, bool bike_side_car)
: Vehicle(bike_make,bike_model,bike_colour,bike_yr,bike_mil), sideCar(bike_side_car){}


/*Function: getSideCar()  */
/*In: none */
/*Out: returns bool*/
/*Purpose: to get the sidecar*/
bool Motorcycle::getSideCar(){return sideCar;}

/*Function: toString()  */
/*In: none */
/*Out: returns string*/
/*Purpose: print out the Car info*/
string Motorcycle::toString()
{
	ostringstream make_model;
	ostringstream info;
	ostringstream side_car;
	make_model << getMake() << " "<<getModel();

	if(getSideCar() == true){ //check to see if there is a sidecar
		side_car<<" has a sidecar";
	}
	else{
		side_car<<" doesn't have a sidecar";
	}

	info <<"\t" << setw(7) <<"MotorCycle: " <<getColour() <<" "
		 << getYear() << " "<< setw(17) << make_model.str() << " ("
		 << getMilage() << "km)," << " " <<side_car.str()<< endl;

	return info.str();
}