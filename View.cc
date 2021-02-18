#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "Customer.h"
#include "Vehicle.h"
#include "Mechanic.h"
#include "LinkedList.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Bob's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n";
    cout<< "        3. Add Vehicle\n\n";
    cout<< "        4. Remove Customer\n\n";
    cout<< "        5. Remove Vehicle\n\n";
    cout<< "        6. Print Mechanics\n\n";
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 6) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}

void View::displayInvalid() { cout << "Invalid choice." << endl << endl; }

void View::promptUserInfo(string &fname, string &lname, string &address, string &phone) {
    cout << "\nFirst name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone number: ";
    getline(cin, phone);
    cout<<endl;
}
/*Function: promptVehicleType  */
/*In: int& */
/*Out: none */
/*Purpose: prompt the user for which vehicle type they wish to add*/
void View::promptUserVehicleType(int &userChoice)
{
    cout<<"Vehicle Type {1: Car, 2: Truck, 3: Motorcycle): ";
    userChoice = readInt();
    cout<<endl;
}

void View::promptVehicleInfo(string &make, string &model, string &colour, 
                                int &year, int &mileage) {
    cout<< "Enter in Car Information\n";
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    cout<<endl;
}

/*Function: promptVehicleInfo  */
/*In: string,string,string,int,int,axle */
/*Out: none */
/*Purpose: get the user input for truck info*/
void View::promptVehicleInfo(string &make, string &model, string &colour,
                                 int &year, int &mileage, int &axle)
{
    cout<< "Enter in Truck Information\n";
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    cout << "Axle: "; //for trucks
    axle = readInt(); 
    cout<<endl;
}

/*Function: promptVehicleInfo  */
/*In: string,string,string,int,int,bool */
/*Out: none */
/*Purpose: get the user input for motorcycle info*/
void View::promptVehicleInfo(string &make, string &model, string &colour,
                                 int &year, int &mileage, bool &sideCar)
{
    string userInput;

    cout<< "Enter in Motorcycle Information\n";
    cout << "\nMake: ";
    getline(cin, make);
    cout << "Model: ";
    getline(cin, model);
    cout << "Colour: ";
    getline(cin, colour);
    cout << "Year: ";
    year = readInt();
    cout << "Mileage: ";
    mileage = readInt();
    
    //for motorcycle
    do{ //repeatidly prompts the user for sidecar until right input is given
        cout << "Has sidecar (y/n): ";
        getline(cin,userInput);

        if((userInput !="y") && (userInput !="n")) //if not valid input then display error
        {
       displayInvalid();
        }
    
    }while((userInput !="y") && (userInput !="n"));    
    

    if(userInput == "y") //checks the user input if "y" then there is a sidecar if "n" then no side car
    {
        sideCar = true;     
    }
    else if(userInput == "n")
    {
        sideCar = false;   
    }

    cout<<endl;
}
void View::promptUserId(int &id) {
    cout << "Customer ID: ";
    id = readInt();
    cout<<endl;
}

void View::printCustomers(LinkedList<Customer>& arr) const {
    cout << endl << "CUSTOMERS: " << endl << endl << arr << endl;
}

void View::printMechanics(LinkedList<Mechanic>& m) const {
    cout << endl << "MECHANICS: " << endl << endl << m << endl;
   
}

void View::pause() const {
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() const {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}

void View::promptVehicle(int numVehicles, int &choice) {
    cout << "Vehicle (0 - " << numVehicles-1 << "): ";
    choice = readInt();
    cout << endl;
}
