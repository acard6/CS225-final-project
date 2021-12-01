#include "DataImport.h"
#include "Airport.h"
#include "Route.h"
#include "adjList.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace DataImport;

int main()
{
    string airports = "./data/airports.dat";
    string routes = "./data/routes.dat";

    ImportDataFile(airports);
    vector<Airport::Airport> vertices = ImportAirports(airports);
    vector<Route::Route> edges = ImportRoutes(routes);

    return 0;
}

