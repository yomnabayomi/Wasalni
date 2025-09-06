//
// Created by Hana on 9/2/2025.
//
#include "admin.h"
using namespace std;
 void admin::bfs(queue<int>& Qlocat, vector<bool>& visited, int start) {
    visited[start] = true;
    Qlocat.push(start);  // Add starting node to queue

    while(!Qlocat.empty()) {
        int curr = Qlocat.front();
        Qlocat.pop();
        cout<<locatId.at(curr).name<<endl;

        for(int neighbor : adj[curr]) {  // Use curr, not start
            if(visited[neighbor] == false) {
                visited[neighbor] = true;
                Qlocat.push(neighbor);
            }
        }
    }
}

void admin::add_location() {
 pair<float,float>coordinates;
string area;
string name;
  cout<<"Enter location name: ";
  cin>>name;
  cout<<"Enter location area: ";
  cin>>area;
  cout<<"Enter location coordinates: ";
  cin>>coordinates.first;
  cin>>coordinates.second;
  numLocations++;
  location locat=location(coordinates,area,name);
  locatId.at(numLocations) = locat;

  cout<<"location added successfully"<<l;
}

admin::admin() {
  numLocations = 0;

}

// Helper function to find location ID by name
int admin::findLocationByName(string locationName) {
    for(const auto pair : locatId) {
        if(pair.second.name == locationName) {
            return pair.first;
        }
    }
    return -1; // Not found
}

void admin::add_road() {
  string name1, name2;
  cout<<"Enter first location name: ";
  cin>>name1;
  cout<<"Enter second location name: ";
  cin>>name2;
 int firstId = findLocationByName(name1);
  int secondId = findLocationByName(name2);
   if(firstId == -1 || secondId == -1) {
        cout << "One or both locations not found!" << endl;
        return;
    }

    // Add bidirectional road
    adj[firstId].push_back(secondId);
    adj[secondId].push_back(firstId);

    cout << "Road added successfully!" << endl;
}