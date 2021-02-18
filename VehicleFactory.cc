#include <iostream>
using namespace std;
#include "VehicleFactory.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

/*Function: create()  */
/*In: string,string,string,int,int */
/*Out: returns Vehicle* */
/*Purpose: to create a new Car*/
Vehicle* VehicleFactory::create(string veh_make, string veh_model, string veh_colour, int veh_yr, int veh_mil)
{
	//car
	newVeh = new Car(veh_make,veh_model,veh_colour,veh_yr,veh_mil);

	return newVeh;
}

/*Function: create()  */
/*In: string,string,string,int,int,int */
/*Out: returns Vehicle* */
/*Purpose: to create a new Truck*/
Vehicle* VehicleFactory::create(string veh_make, string veh_model, string veh_colour,int veh_yr,int veh_mil,int veh_axle)
{
	//truck
	newVeh = new Truck(veh_make,veh_model,veh_colour,veh_yr,veh_mil,veh_axle);
	return newVeh;
}

/*Function: create()  */
/*In: string,string,string,int,int,bool */
/*Out: returns Vehicle* */
/*Purpose: to create a new Motorcycle */
Vehicle* VehicleFactory::create(string veh_make,string veh_model,string veh_colour, int veh_yr, int veh_mil, bool veh_sideCar)
{
	//motorcycle
	newVeh = new Motorcycle(veh_make,veh_model,veh_colour,veh_yr,veh_mil,veh_sideCar);
	return newVeh;
}