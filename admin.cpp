//
// Created by Hana on 9/2/2025.
//
#include "admin.h"
#include "driver.h"
#include "user.h"
using namespace std;


// I need to increment the numLocation in the location's contructor 
int admin::numLocations = 0;
int admin :: numdrivers =0 ;
int admin :: numusers = 0;

// increment it then add it to the unordered map

admin::admin()
{
    numLocations = 0;
}

// helper Functions
bool admin ::location_is_found(int loctID)
{
    return (loctID != -1);
}
bool admin ::road_is_found(int outerIndex, int innerIndex)
{


    auto &neighbors = adj[outerIndex]; 

    auto it = std::find_if(neighbors.begin(), neighbors.end(),
                           [innerIndex](const std::pair<int,float> &p) {
                               return p.first == innerIndex; // match by node ID
                           });

    if (it != neighbors.end())
    {
        neighbors.erase(it);
        return true;
    }

    return false;                       




//    auto it = find(adj[outerIndex].begin(), adj[outerIndex].end(), innerIndex);
//     if (it != adj[outerIndex].end())
//     {
//         adj[outerIndex].erase(it);
//         return true;
//     }

//     return false;

}


int admin::findLocationByName(const string &locationName)
{
    // loop on unordered map(locationByid)
    for (const auto & pair : locationById)
    {
        if (pair.second.name == locationName)
        {
            return pair.first;
        }
    }
    return -1; // Not found
}


bool admin::edge_exists(int u, int v) {
    auto &neighbors = adj[u];
    return std::any_of(neighbors.begin(), neighbors.end(),
                       [v](const std::pair<int,float>& p) {
                           return p.first == v;
                       });
}

// update Functions(add , delete)

// add location , road
void admin :: addGraph(){
    // to be implemented 
    // inserting multiple roads and locations 
    // updating the adj list and I need their id's 
    // updating the locationbyId => id , location with the new locations  
}

void admin::add_location()
{
    pair<float, float> coordinates;
    string area;
    string name;
    cout << "Enter location name: ";
    cin >> name;
    cout << "Enter location area: ";
    cin >> area;
    cout << "Enter location coordinates: ";
    cin >> coordinates.first;
    cin >> coordinates.second;
    numLocations++;
    location locat(coordinates, name);
    locationById[numLocations] = locat;
    // Initialize adjacency list for this location ID
    adj[numLocations] = {}; // empty vector<int> ready for neighbors

    cout << "location added successfully" << l;
}
void admin::add_road(){

    string name1, name2;
    cout << "Enter first location name: ";
    cin >> name1;
    cout << "Enter second location name: ";
    cin >> name2;
    int firstId = findLocationByName(name1);
    int secondId = findLocationByName(name2);
    // used the bool function change it  if you don't like it
    if (!(location_is_found(firstId) && location_is_found(secondId)))
    {
        cout << "One or both locations not found!" << endl;
        return;
    }



    // check for existing edge => implement edge_exist 
if (edge_exists(firstId, secondId)) {
    cout << "Road already exists!" << endl;
    return;
}




    // Add bidirectional road
    float weight = lengthBetNodes(firstId , secondId);
    adj[firstId].push_back({secondId , weight});
    adj[secondId].push_back({firstId , weight});

    cout << "Road added successfully!" << endl;
}

// delete location , road
void admin ::delete_location()
{

    string loctName;
    cout << "Enter the location name you want to delete : " << l;
    cin >> loctName;

    int loctID = findLocationByName(loctName);

    if (!location_is_found(loctID))
    {
        cout << "The location is not found" << l;
        return;
    }
    string confirmation;
    cout << "Are you sure you want to delete  Y/N" << loctName << l;
    cin >> confirmation;

    if (confirmation == "N")
    {
        cout << "deleting location  process is canceled" << l;
        return;
    }

auto it = adj.find(loctID);
if (it != adj.end()) {
    // for each neighbor of loctID, remove the reverse edge
    for (const auto &p : it->second) {
        int child = p.first;

        // remove (child -> loctID) directly here
        auto &neighbors = adj[child];
        neighbors.erase(
            std::remove_if(neighbors.begin(), neighbors.end(),
                           [loctID](const std::pair<int,float> &pr) {
                               return pr.first == loctID;
                           }),
            neighbors.end()
        );
    }
    // finally remove adjacency list for loctID
    adj.erase(it);
}

    // for (const auto [child , wieight ]: adj[loctID])
    // {

    //     adj[child].erase(
    //         remove(adj[child].begin(), adj[child].end(), loctID),
    //         adj[child].end());

    //     // vec[outerIndex].erase(vec[outerIndex].begin() + innerIndex);
    // }

    // adj.erase(loctID);
    locationById.erase(loctID);

    cout << "location is deleted successfully";
}
void admin ::delete_road()
{

    string city1, city2;
    cout << "Enter the the two locations names the road exist between" << l;
    cin >> city1 >> city2;
    int first_id = findLocationByName(city1);
    int second_id = findLocationByName(city2);

    string confirmation;
    cout << "Are you sure you want to delete road between  " << city1 << ' ' << city2 << "Y/N" << l;
    cin >> confirmation;

    if (confirmation == "N")
    {
        cout << "deleting road process is canceled" << l;
        return;
    }

    if (!(location_is_found(first_id) && location_is_found(second_id)))
    {
        cout << "One or both locations not found!" << endl;
        return;
    }



 // undirected graph → must delete both sides
    bool removedA = road_is_found(first_id, second_id);
    bool removedB = road_is_found(second_id, first_id);

    if (removedA && removedB)
    {
        cout << "Road is deleted successfully" << l;
    }
    else
    {
        cout << "Road is not found between the two locations " << l;
    }
}

// Traversal functions
void admin ::dfs_caller(vector<bool> &visited)
{

    for (const auto [id, loc] : locationById)
    {
        if (!visited[id])
        {
            dfs(id, visited);
        }
    }
}
void admin ::dfs(int node, vector<bool> &visited){
    visited[node] = true;
    cout << locationById[node].name << ' ';

    auto it = adj.find(node);
    if (it == adj.end()) return;

    for (const auto &p : it->second) { // p.first = neighbor, p.second = weight
        int neighbor = p.first;
        if (!visited[neighbor])
            dfs(neighbor, visited);
    }

    // for (auto [neighbor , weight]: adj[node])
    // {
    //     if (!visited[neighbor])
    //         dfs(neighbor, visited);
    // }
}
void admin::bfs(queue<int> &Qlocat, vector<bool> &visited, int start){
    visited[start] = true;
    Qlocat.push(start); // Add starting node to queue

    while (!Qlocat.empty())
    {
        int curr = Qlocat.front();
        Qlocat.pop();
        cout << locationById.at(curr).name << endl;



        auto it = adj.find(curr);
        if (it == adj.end()) continue;

        for (const auto &p : it->second) {
            int neighbor = p.first;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                Qlocat.push(neighbor);
            }
        }

        // for (auto [neighbor , weight ] : adj[curr])
        // { // Use curr, not start
        //     if (visited[neighbor] == false)
        //     {
        //         visited[neighbor] = true;
        //         Qlocat.push(neighbor);
        //     }
        // }
    }
}
void admin :: displayData () {
    // to be implemented 
}


// id node 1 , id node 2 
float admin :: lengthBetNodes (int a , int b){



double xA , yA , xB , yB ;

xA =  locationById[a].coordinates.first ;
yA =  locationById[a].coordinates.second ;
xB=   locationById[b].coordinates.first ;
yB=   locationById[b].coordinates.second ;


double diffX = xA - xB  , diffY = yA - yB ;

double  dist = sqrt (diffX * diffX + diffY * diffY  );

return static_cast<float>(dist); // convert at the end



}