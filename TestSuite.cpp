#include "TestSuite.h"

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
bool TestSuite::smallADJListComparison(){

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