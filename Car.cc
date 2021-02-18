#include <iostream>
using namespace std;
#include "Car.h"


Car::Car(string mak, string mod, string co, int yr, int mil): Vehicle(mak,mod,co,yr,mil){}


/*Function: toString()  */
/*In: none */
/*Out: returns string*/
/*Purpose: print out the Car info*/
string Car::toString()
{	
	
	ostringstream make_model;
	ostringstream info;
	make_model << getMake() << " "<<getModel();

	info <<"\t" << setw(7) <<"Car: " <<getColour() <<" "
		 << getYear() << " "<< setw(17) << make_model.str() << " ("
		 << getMilage() << "km)" << endl;

	return info.str();


}