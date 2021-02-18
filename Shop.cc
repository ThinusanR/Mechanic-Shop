#include "Shop.h"
#include "defs.h"

Shop::Shop() : numMechanics(0) { }

Shop::~Shop() {
    for (int i=0; i < numMechanics; i++) 
        delete mechanics[i];
}

Shop& Shop::operator+=(Customer* c) { 
    customers += c; 
    return *this;
}

Shop& Shop::operator-=(Customer* c) { 
    customers -= c; 
    return *this;
}

Customer* Shop::getCustomer(int id)  
{ 
    //loop through the customer linkedlist
    // and using the subscript operator we check if the id matches
    
    for(int j =0 ; j < customers.getSize();j++){
        if(customers[j]->getId() == id){
            return customers[j];
        }
    }

    return 0;

} 

//changed to use the template linkedlist
LinkedList<Customer>& Shop::getCustomers() { return customers; }

Shop& Shop::operator+=(Mechanic* m) {    
   
    mechanics += m; //changed to use the += 

    return *this;
}

int Shop::getNumMechanics()     { return numMechanics; }

//changed to use the template linkedlist
LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }
