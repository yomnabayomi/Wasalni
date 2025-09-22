# Wasalni

**Wasalni** is a ride-hailing simulation platform that allows users to request rides and drivers to fulfill them on a dynamic graph-based map. The system simulates realistic driver movement, dynamic routing, and efficient pickup/drop-off using shortest-path algorithms.

---

## Table of Contents
- [Features](#features)  
- [System Overview](#system-overview)  
- [Classes & Structure](#classes--structure)  
- [Workflow](#workflow)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Future Enhancements](#future-enhancements)

---

## Features
- Users can request rides from their current location to a destination.  
- Drivers are dynamically located on streets (edges) rather than fixed nodes.  
- Automatic nearest-driver assignment using Dijkstra algorithm.  
- Two-stage routing:  
  1. Driver → User pickup  
  2. User pickup → Destination  
- Simulation of driver movement along edges.  
- Flexible graph-based map structure for streets and intersections.  

---

## Tech Stack  
- **Language**: C++  
- **Concepts**: Object-Oriented Programming (OOP), Graph Theory, Shortest Path Algorithms  
- **Data Structures**: Adjacency List, Priority Queue  
- **Tools**: Git, GitHub, VS Code

 ---

## System Overview
Wasalni models the city as a **graph**, where:
- **Nodes** represent intersections.  
- **Edges** represent streets with weights (distance or travel time).  
- **Drivers** can exist anywhere on an edge, represented by temporary nodes in the graph.  
- **Users** are located at nodes and have a destination node.  

The system uses **Dijkstra's algorithm** to:
1. Find the closest available driver to a user.  
2. Compute the shortest path from pickup to the user’s destination.  

---

## Classes & Structure

### User Class
- Attributes: `id`, `name`, `currentLocation`, `destination`.  
- Methods: `requestRide()`, getters/setters.

### Driver Class
- Attributes: `id`, `name`, `currentLocation`, `available`, `currentEdge`.  
- Methods: `moveToNode()`, `setAvailability()`, getters/setters.

### Graph Class
- Represents the city map.  
- Attributes: adjacency list of nodes and edges.  
- Methods: `addEdge()`, `getNeighbors()`, `dijkstra()`.

### RideManager / Dispatcher
- Manages drivers and ride requests.  
- Assigns the nearest available driver using shortest-path computation.  
- Coordinates pickup and drop-off paths.  

---

## Workflow
1. **User requests a ride** → system checks for available drivers.  
2. **Find nearest driver** using Dijkstra from driver’s current position (fake node if on an edge).  
3. **Driver moves to pickup** → driver’s temporary node is connected to the street nodes.  
4. **Pickup occurs** → driver’s availability updated.  
5. **Route to destination** → Dijkstra finds shortest path from pickup to user’s destination.  
6. **Drop-off** → driver becomes available again.

---

## Installation
1. Clone the repository:
```bash
git clone https://github.com/yourusername/wasalni.git
```
2. Navigate to the project folder:
```bash
cd wasalni
```
3. Compile and run (example for C++):
```bash
g++ main.cpp -o wasalni
./wasalni
```
*(Adjust commands based on your implementation language.)*

---

## Usage
- Add drivers and users through the admin interface.  
- Assign driver positions dynamically on streets.  
- Request rides and watch the system assign drivers and compute routes.  
- Visualize movement on the map (if implemented).  

---

## Future Enhancements
- Real-time traffic simulation and dynamic edge weights.  
- Multiple concurrent ride requests with optimized driver assignment.  
- Interactive GUI to display driver and user movements on the map.  
- Integration with real-world coordinates (GPS) for realistic routing.  

---

**Wasalni** is designed as a foundation for a full ride-hailing system with flexible extensions and realistic simulations of drivers and users in a city graph.
