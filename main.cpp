#include "adjList.h"
#include "cs225/PNG.h"
#include "TestSuite.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    string airportData = "./data/airports.csv";
    string routeData = "./data/routes.csv";

    vector<Airport> vertices = ImportAirports(airportData);
    vector<Route> edges = ImportRoutes(routeData);

    return 0;
}