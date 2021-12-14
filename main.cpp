#include "adjList.h"
#include "cs225/PNG.h"
#include "TestSuite.h"
#include "PngMap.h"

int main(int argc, char *argv[])
{
    // string airportData = "./data/airports.csv";
    // string routeData = "./data/routes.csv";

    // vector<Airport> vertices = ImportAirports(airportData);
    // vector<Route> edges = ImportRoutes(routeData);

    // the actual graph made from the adjacency list class
    // ADJList graphList;
    // graphList.addVertex(vertices);
    // for (int i=0; i<edges.size(); i++){
    //     graphList.addEdge(edges[i]);
    // }

    if(argc >= 2)
    {
        string param(argv[1]);
        bool test = false;

        if(param == "TestArgs") cout << "Test successful" << endl;
        if(param == "TestAirportImport") test = TestAirportImport(stoi(argv[2]), argv[3]);
        if(param == "TestRouteImport") test = TestRouteImport(stoi(argv[2]), argv[3]);
        if(param == "PngAirportComparison") test = PngAirportComparison(stoi(argv[2]));
        if(param == "PngRouteComparison") test = PngRouteComparison(stoi(argv[2]));

        if(test) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }

    return 0;
}