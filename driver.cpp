//
// Created by Hana on 9/2/2025.
//

#include "driver.h"

driver::driver(string name ,string email,string telephone,string pass) {
    this->name = name;
    this->email = email;
    this->telephone = telephone;
    password=pass;
}
void driver::setdriverlocation(location curr_locat,pair<int,int>street) {
    this->curr_location=curr_locat;
    this->street=street;
}
void driver::setavailability(bool available) {
    this->available=available;
}