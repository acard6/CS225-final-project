#include "TestSuite.h"

using namespace std;


/*
	Data import
*/
//Compare the nth value in the dataset to the test airport
bool TestAirportImport(int n, Airport* airport)
{	
	if(!airport) return false;

	vector<Airport> data = ImportAirports("./data/airports.csv");

	return data[n] == *airport;
}

//Compare the nth value in the dataset to the test route
bool TestRouteImport(int n, Route* route)
{
	if(!route) return false;

	vector<Route> data = ImportRoutes("./data/routes.csv");

	return data[n] == *route;
}

/*
	PNG Airport tests
*/
bool PngAirportComparison(int n)
{
	
}

/*
	Adjacency List
*/
void smallADJList(){
	string airportData = "./data/smallairport.csv";
    string routeData = "./data/smallroutes.csv";

    vector<Airport> vertices = ImportAirports(airportData);
    vector<Route> edges = ImportRoutes(routeData);

    ADJList* graphList;
    graphList->addVertex(vertices);
    for (int i=0; i<edges.size(); i++){
        graphList->addEdge(edges[i]);
    }	

	for (int i=0; i < graphList->size(); i++){
		if (graphList->list[i] != NULL){ 
			ADJList::edgeList list = graphList->list[i]->second;
			ADJList::edge* temp = list.getHead(); 
			for (int j=0; j<list.getSize()-1; j++){
				
				temp = temp->next; 
			}
		}
	}

}

/*
	Route Rendering
*/
bool PngRouteComparison()
{

}

/*
	Graph Coloring
*/
bool PngSimpleRouteHighlightComparison(Airport source, Airport dest)
{

}

bool PngComplexRouteHighlightComparison(Airport source, Airport dest)
{

}