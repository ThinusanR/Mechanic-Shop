#include <iostream>
using namespace std;
#include "Truck.h"

Truck::Truck(string truck_make,string truck_model,string truck_colour,int truck_year,int truck_milage,int truck_axle)
 : Vehicle(truck_make,truck_model,truck_colour,truck_year,truck_milage), axle(truck_axle) {}


/*Function: getSideCar()  */
/*In: none */
/*Out: returns bool*/
/*Purpose: to get the sidecar*/
int Truck::getAxle(){return axle;}
 

/*Function: toString()  */
/*In: none */
/*Out: returns string*/
/*Purpose: print out the Car info*/
string Truck::toString()
 {
 	ostringstream make_model;
	ostringstream info;
	make_model << getMake() << " "<<getModel();

	info <<"\t" << setw(7) <<"Truck: " <<getColour() <<" "
		 << getYear() << " "<< setw(17) << make_model.str() << " ("
		 << getMilage() << "km)," << " " <<getAxle()<<" Axles"<< endl;

	return info.str();
 }