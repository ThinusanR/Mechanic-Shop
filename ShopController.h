#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include "View.h"
#include "Shop.h"
#include "Vehicle.h"
#include "VehicleFactory.h"

class ShopController {

    public:
        ShopController();
        void launch();
    private:
        Shop mechanicShop;
        View view;
        void initShop();
        VehicleFactory production; // new
};

#endif
