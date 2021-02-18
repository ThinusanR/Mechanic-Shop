#ifndef VIEW_H
#define VIEW_H


#include "LinkedList.h"
#include "Mechanic.h"
#include "Customer.h"

class View {

    public:
        void mainMenu(int&);
        void printCustomers(LinkedList<Customer>&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void promptVehicleInfo(string&, string&, string&, int&, int&, int&);//new
        void promptVehicleInfo(string&, string&, string&, int&, int&, bool&);//new
        void promptVehicle(int, int&);
        void printMechanics(LinkedList<Mechanic>&) const;
        void promptUserVehicleType(int&);//new
    private:
        int readInt() const;
};

#endif
