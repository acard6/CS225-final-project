#include "adjList.h"
#include "cs225/PNG.h"
#include "TestSuite.h"
#include "Map.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string airportData = "./data/airports.csv";
    string routeData = "./data/routes.csv";

    vector<Airport> vertices = ImportAirports(airportData);
    vector<Route> edges = ImportRoutes(routeData);

    // the actual graph made from the adjacency list class
    ADJList::ADJList graphList;
    graphList.addVertex(vertices);
    for (int i=0; i<edges.size(); i++){
        graphList.addEdge(edge[i]);
    }

    return 0;
}