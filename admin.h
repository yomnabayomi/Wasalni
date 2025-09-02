//
// Created by Hana on 9/2/2025.
//
#include<string>
#include<iostream>
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H

struct location{
pair<float,float>coordinates;
string area;
//constructor
location(pair<float,float>coordinates,string area){
  this->coordinates = coordinates;
  this->area = area;
}
};

class admin {

};



#endif //ADMIN_H
