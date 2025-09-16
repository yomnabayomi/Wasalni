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



void driver :: update_progress (float delta , admin & a){
    progress += delta ;
   // if(! (progress % 1.0 ))


   if (progress >= 1.0 ){
      progress -= 1.0;
      snapToEdge(this->street.second , a);
      
   }

  

}


void driver :: snapToEdge (int node , admin & a){
int prevNode = this->street.first ;

 vector <int> neighbors = a.adj[node];

neighbors.erase(remove(neighbors.begin(),neighbors.end(),prevNode));

    
    if(! neighbors.empty() ){
        int randomIndex = rand() % neighbors.size();
        this->street = {node , neighbors[randomIndex]};
    }else{
        this->street = {node , prevNode};
    }

    

    
   

    // there's a case I should handle -> bouncing forever between these to two nodes 



}



void driver :: set_edge(pair <int , int > street){
    this -> street = street ;
}