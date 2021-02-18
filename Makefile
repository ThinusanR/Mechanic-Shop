OBJ = main.o ShopController.o View.o Shop.o Customer.o Vehicle.o Mechanic.o Person.o Car.o Truck.o Motorcycle.o VehicleFactory.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -Wall -c main.cc -g

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -Wall -c ShopController.cc -g

View.o:	View.cc View.h 
	g++ -Wall -c View.cc -g

Shop.o:	Shop.cc Shop.h Mechanic.h LinkedList.h
	g++ -Wall -c Shop.cc -g

Customer.o:	Customer.cc Customer.h Person.h Vehicle.h 
	g++ -Wall -c Customer.cc -g

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -Wall -c Vehicle.cc -g

Mechanic.o: Mechanic.cc Mechanic.h Person.h
	g++ -Wall -c Mechanic.cc -g

Person.o: Person.h Person.cc
	g++ -Wall -c Person.cc -g

Car.o: Car.h Car.cc Vehicle.h
	g++ -Wall -c Car.cc -g

Truck.o: Truck.h Truck.cc Vehicle.h
	g++ -Wall -c Truck.cc -g

Motorcycle.o: Motorcycle.h Motorcycle.cc Vehicle.h
	g++ -Wall -c Motorcycle.cc -g

VehicleFactory.o: VehicleFactory.h VehicleFactory.cc Vehicle.h
	g++ -Wall -c VehicleFactory.cc -g

clean:
	rm -f $(OBJ) mechanicshop
