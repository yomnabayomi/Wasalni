//
// Created by Hana on 9/2/2025.
//

#ifndef DRIVER_H
#define DRIVER_H
#include "admin.h"
#include<set>


class driver {
location curr_location=location({0,0}," ");
bool available = true;
string name;
string email;
string telephone;
string password;

pair<int,int>street; // node1 , node2
driver(string name ,string email,string telephone,string pass);
void setdriverlocation(location curr_locat,pair<int,int>street);
void setavailability(bool available);
};



#endif //DRIVER_H
