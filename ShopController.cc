#include "ShopController.h"

ShopController::ShopController() {

    initShop();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } else if (choice == 2) {
            string fname, lname, address, phone;
            view.promptUserInfo(fname, lname, address, phone);
            mechanicShop += new Customer(fname, lname, address, phone);
            view.pause();
        } else if (choice == 3) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                string make, model, colour;
                int year, milage,user_choice,axle;
                bool sideCar;
               
               //prompt the user for which vehicles type and then get the info 
                view.promptUserVehicleType(user_choice);
                if(user_choice == 1)
                {   //car
                    view.promptVehicleInfo(make, model, colour, year, milage);
                    *cust += production.create(make,model,colour,year,milage);
                }
                else if(user_choice == 2)
                {
                    //truck
                    view.promptVehicleInfo(make, model, colour, year, milage,axle);
                    *cust += production.create(make,model,colour,year,milage,axle);

                }else if(user_choice == 3)
                {
                    //motorcycle
                    view.promptVehicleInfo(make, model, colour, year, milage,sideCar);
                    *cust += production.create(make,model,colour,year,milage,sideCar);

                }else{
                    view.displayInvalid();
                }

            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 4) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                mechanicShop -= cust;
                delete cust;
            } else {
                view.displayInvalid();
            }
            view.pause();      
        } else if (choice == 5) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);  
            if (cust != 0) {
                int choice;
                view.promptVehicle(cust->getNumVehicles(), choice);
				if (choice < 0|| (cust->getNumVehicles()-1) < choice) {
					view.displayInvalid();
				} else {
					Vehicle* v = cust->getVehicles()[choice];
                	cust->getVehicles() -= v;
                	delete v;
				}
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 6) {
            //changed 
            view.printMechanics(mechanicShop.getMechanics());
            view.pause();
        } else {
            break;
        }
    }
}


void ShopController::initShop() { //changed to now use VehicleFactory

    Customer* newCustomer;
    Vehicle* newVehicle;
    Mechanic* newMechanic;

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.", 
                                        "(613)728-9568");
    
    newVehicle = production.create("Ford", "Fiesta", "Red", 2007, 100000);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Toyota","Tacoma","Blue",2018,1000,2);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Ford","F150","Black",2017,1000,3);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;

   
    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.", 
                                        "(613)345-6743");
  
    newVehicle = production.create("Subaru", "Forester", "Green", 2016, 40000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;

    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.", 
                                        "(613)123-7456");
   
    newVehicle = production.create("Honda", "Accord", "White", 2018, 5000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("Volkswagon", "Beetle", "White", 1972, 5000);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.", 
                                        "(613)234-9677");
    
    newVehicle = production.create("Toyota", "Camery", "Black", 2010, 50000);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Mack","Granite","Red",2000,500000,8);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;
    

    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.", 
                                        "(613)456-2345");
    
    newVehicle = production.create("Toyota", "Corolla", "Green", 2013, 80000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("Toyota", "Rav4", "Gold", 2015, 20000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("Toyota", "Prius", "Blue", 2017, 10000);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Kawasaki", "Z650", "Grey", 2014, 5000, false);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Kawasaki", "Ninja", "Blue", 2018, 1000, false);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;

    
    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.", 
                                        "(613)432-7622");
  
    newVehicle = production.create("GM", "Envoy", "Purple", 2012, 60000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("GM", "Escalade", "Black", 2016, 40000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("GM", "Malibu", "Red", 2015, 20000);
    (*newCustomer) += newVehicle;
    
    newVehicle = production.create("GM", "Trailblazer", "Orange", 2012, 90000);
    (*newCustomer) += newVehicle;

    newVehicle = production.create("Harley", "Touring", "Black", 2006, 8000, true);
    (*newCustomer) += newVehicle;
    mechanicShop += newCustomer;



    newMechanic = new Mechanic("Bill", "Taylor", "54 Park Place", 
                                        "(613)826-9847", 75000);
    mechanicShop += newMechanic;
    newMechanic = new Mechanic("Steve", "Bane", "77 Oak St.", 
                                        "(613)223-4653", 60000);
    mechanicShop += newMechanic;
    newMechanic = new Mechanic("Jane", "Smyth", "10 5th Ave.", 
                                        "(613)762-4678", 71000);
    mechanicShop += newMechanic;




}
