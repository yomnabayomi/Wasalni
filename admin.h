//
// Created by Hana on 9/2/2025.
//
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#define l endl;
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H

struct location{
pair<float,float>coordinates;
string area;
string name;

//constructor
location(pair<float,float>coordinates,string area,string name){
  this->coordinates = coordinates;
  this->area = area;
  this->name = name;
}
};

class admin {

public:
  static int numLocations;

vector<vector<int>>adj; //adj list
unordered_map<int,location>locatId;//assign id to every location to facilitate the searching

  //functions
  void bfs(queue<int>& Qlocat, vector<bool>& visited, int start);
  void add_location();
   int findLocationByName(string locationName);
  void add_road();
  admin();
  // Helper function to find location ID by name



};



#endif //ADMIN_H
