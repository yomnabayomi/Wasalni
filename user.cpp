//
// Created by Hana on 9/2/2025.
//

#include "user.h"

user :: user (string name , string email , string telephone , string password){
    this->name = name ;
    this->email = email;
    this->telephone = telephone ;
    this->password =  password ;
}

//getters
location user :: getCurrLocation(){
    return this->curr_location;
}

location user :: getDestination(){
    return this-> destination ;
}

//setters

void user :: setCurrLocation(int x , int y , string name){
    this -> curr_location = location({x,y},name);
}


void user :: setDestination(int x , int y , string name){
    this -> destination= location({x,y},name);
}


void user :: requestRide(admin & Admin ){
    string curr, dest ;
    cout << "Enter the pick up and drop off locations ' names :" << l ;
    cin >> curr >> dest ;
    int firstID = Admin.findLocationByName(curr);
    int secondID = Admin.findLocationByName(dest);
    if(!(Admin.location_is_found(firstID) && Admin.location_is_found(secondID))){
         cout << "One or both locations not found!" << endl;
        return;
    }
    location current = Admin.locationById[firstID];
    location destination = Admin.locationById[secondID];


    // here we should add function call 
    // after implementing dijkstra we should call it with current and destination being the parameters 

}