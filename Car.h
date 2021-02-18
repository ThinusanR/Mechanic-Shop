#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

class Car : virtual public Vehicle{

 public:
 	Car(string="",string="",string="", int=0, int=0);
 	string toString();

};
#endif