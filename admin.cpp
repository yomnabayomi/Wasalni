//
// Created by Hana on 9/2/2025.
//
#include "admin.h"
using namespace std;





int admin::numLocations = 0; 

admin::admin() {
  numLocations = 0;
}


// helper Functions 
bool admin :: location_is_found (int loctID){
    return (loctID != -1);
}
bool admin :: road_is_found(int outerIndex , int innerIndex){
    auto it = find(adj[outerIndex].begin() , adj[outerIndex].end() , innerIndex);
     if (it != adj[outerIndex].end()){
      adj[outerIndex].erase(it);
      return true;
     }

     return false ;
}
int admin::findLocationByName(const string &locationName) {
     // loop on unordered map
    for(const auto pair : locationById) {
        if(pair.second.name == locationName) {
            return pair.first;
        }
    }
    return -1; // Not found
}





// update Functions(add , delete)



//add location , road 

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
  location locat=location(coordinates,name);
  locationById.at(numLocations) = locat;

  // push_back the location in the adjacency lit ??

  cout<<"location added successfully"<<l;
}
void admin::add_road() {

  string name1, name2;
  cout<<"Enter first location name: ";
  cin>>name1;
  cout<<"Enter second location name: ";
  cin>>name2;
 int firstId = findLocationByName(name1);
  int secondId = findLocationByName(name2);
  // used the bool function change it  if you don't like it 
   if(!(location_is_found(firstId) && location_is_found(secondId))) {
        cout << "One or both locations not found!" << endl;
        return;
    }

    // Add bidirectional road
    adj[firstId].push_back(secondId);
    adj[secondId].push_back(firstId);

    cout << "Road added successfully!" << endl;
}





// delete location , road 
void admin :: delete_location(){


    string loctName ;
    cout << "Enter the location name you want to delete : " << l ;
    cin >> loctName ;

    int loctID = findLocationByName(loctName);



    if(!location_is_found(loctID)){
        cout << "The location is not found" << l;
        return ;
    }
string confirmation ;
    cout << "Are you sure you want to delete  Y/N" << loctName << l ;
    cin >> confirmation ;

    if(confirmation == "N"){
    cout << "deleting location  process is canceled" << l ;
    return ;

    }
for (const auto child : adj[loctID]){

   adj[child].erase(
    remove(adj[child].begin(), adj[child].end(), loctID),
    adj[child].end()
);


    // vec[outerIndex].erase(vec[outerIndex].begin() + innerIndex);
}
   
adj.erase(adj.begin() + loctID);

locationById.erase(loctID);

cout << "location is deleted successfully" ;


}
void admin :: delete_road () {

    string city1 , city2 ; 
    cout << "Enter the the two locations names the road exist between" << l ;
    cin >> city1 >> city2 ;
    int first_id = findLocationByName(city1);
    int second_id = findLocationByName(city2);

string confirmation ;
    cout << "Are you sure you want to delete road between  " << city1  << ' ' << city2 << "Y/N" << l ;
    cin >> confirmation ;

    if(confirmation == "N"){
    cout << "deleting road process is canceled" << l ;
    return ;

    }

     if(!(location_is_found(first_id) && location_is_found(second_id))) {
        cout << "One or both locations not found!" << endl;
        return;
    }

if(road_is_found (first_id, second_id) && road_is_found(second_id , first_id)){
cout << " road is deleted successfully" << l;
return ;
}
   cout << "road is not found between the two locations " << l;


}




// Traversal functions 

void admin :: dfs_caller (vector<bool>& visited){


for(const auto [id,loc] : locationById){
    if(!visited[id]){
        dfs(id ,visited );
    }
}

}
void admin :: dfs (int node , vector<bool>& visited){
    visited[node] = true ;
    cout << locationById[node].name << ' ' ;
    for(auto child : adj[node]){
        if(!visited[child])
        dfs(child , visited);
    }
}
 void admin::bfs(queue<int>& Qlocat, vector<bool>& visited, int start) {
    visited[start] = true;
    Qlocat.push(start);  // Add starting node to queue

    while(!Qlocat.empty()) {
        int curr = Qlocat.front();
        Qlocat.pop();
        cout<<locationById.at(curr).name<<endl;

        for(int neighbor : adj[curr]) {  // Use curr, not start
            if(visited[neighbor] == false) {
                visited[neighbor] = true;
                Qlocat.push(neighbor);
            }
        }
    }
}
