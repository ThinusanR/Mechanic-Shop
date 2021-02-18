Purpose: replaced CustomerList and VehicleLis with a template class call LinkedList and moved the get(int) for customerlist into the shop class. Made the Mechanics to be stored in LinkedList and made the nessary changes for it.
Created three classes car,truck and motorcycle which are child classes of vehicle and each class has a toString function with the vehicle class having a pure virtual class. Created a VehicleFactory class which initalizes new car,truck and motorcycle types. Finally changed up shopcontroller so that it now only uses vehiclefactory to add in vehicles and cleaned up the UI.

Compilation Command: make 
Execution Command: ./mechanicshop
Valgrind Command: valgrind ./mechanicshop
Clean files command: make clean 

Files included: 
-main.cc
-Customer.cc
-Customer.h
-Shop.cc
-Shop.h
-Vehicle.cc
-Vehicle.h
-defs.h
-View.cc
-View.h
-ShopController.cc
-ShopController.h
-Person.cc
-Person.h
-Mechanic.cc
-Mechanic.h
-Car.cc
-Car.h
-LinkedList.h
-Motorcycle.cc
-Motorcycle.h
-Truck.cc
-Truck.h
-VehicleFactory.cc
-VehicleFactory.h
-Makefile
