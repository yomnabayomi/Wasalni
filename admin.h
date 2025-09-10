//
// Created by Hana on 9/2/2025.
//
#include <string>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define l endl;
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H

struct location
{
  // should we add weight attribute ??
  pair<float, float> coordinates;
  string name;

  // constructor
  location(pair<float, float> coordinates, string name)
  {
    this->coordinates = coordinates;
    this->name = name;
  }
};

class admin
{

public:
  static int numLocations;

  // why not adding bool vis array
  vector<vector<int>> adj;                   // adj list
  unordered_map<int, location> locationById; // assign id to every location to facilitate the searching

  // functions
  admin();
  // Helper function to find location ID by name
  int findLocationByName(const string &locationName);
  bool location_is_found(int loctId);
  bool road_is_found(int, int);

  void add_location();
  void add_road();

  void delete_location();
  void delete_road();

  void dfs_caller(vector<bool> &visited);
  void dfs(int node, vector<bool> &visited);
  void bfs(queue<int> &Qlocat, vector<bool> &visited, int start);
};

#endif ADMIN_H
