# include "RideManager.h"
#include "admin.h"


void RideManager :: detectOnEdgeDrivers (){
    for (auto [id , D] : Admin.drivers ){
 // Only if driver is really *between* nodes
        if (D.progress > 0.0 && D.progress < 1.0) {
            addTempNodes(D);
        }

    }
}

void RideManager :: addTempNodes (driver & d){

/*
x = (1 - progress) * xA + progress * xB
y = (1 - progress) * yA + progress * yB
*/


int firstNode = d.street.first;
int secondNode = d.street.second;

float x = (1-d.progress ) * Admin.locationById[firstNode].coordinates.first + d.progress *  Admin.locationById[secondNode].coordinates.first ;
float y = (1-d.progress ) * Admin.locationById[firstNode].coordinates.second + d.progress *  Admin.locationById[secondNode].coordinates.second ;
string city1 = Admin.locationById[firstNode].name;
string city2 = Admin.locationById[secondNode].name;

d.curr_location = location( { x , y } , "between" + city1 + "and"  + city2 );


int tempId = Admin.numLocations++ ;
toDeleteNodes.push_back(tempId);


Admin.locationById[tempId] = d.curr_location ;


Admin.adj[firstNode].push_back(tempId);
Admin.adj[tempId].push_back(firstNode);

Admin.adj[secondNode].push_back(tempId);
Admin.adj[tempId].push_back(secondNode);





/*
Connect it to A with distance = progress * length(A,B).
Connect it to B with distance = (1 - progress) * length(A,B).
*/



}