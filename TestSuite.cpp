#include "TestSuite.h"

using namespace std;


/*
	Data import
*/

/*
	PNG Airport tests
*/

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

/*
	Graph Coloring
*/