#pragma once

#include "PngMap.h"
#include "BFS.h"

#include <iostream>

using namespace std;

/*
	Data import
*/
//Compare the nth value in the dataset to the test airport
bool TestAirportImport(int n, string airportString)
{
	vector<string> airportVec = Split(airportString, ",");
	vector<Airport> data = ImportAirports("./data/airports.csv");

	double lat = stod(airportVec[4].c_str(), NULL);
    double lon = strtod(airportVec[5].c_str(), NULL);

    Airport airport(airportVec[0], airportVec[1],
					airportVec[2], airportVec[3],
					lat, lon);


	return data[n] == airport;
}

//Compare the nth value in the dataset to the test route
bool TestRouteImport(int n, string routeString)
{
	vector<string> routeVec = Split(routeString, ",");
	vector<Route> data = ImportRoutes("./data/routes.csv");

	int stops = stoi(routeVec[2]);

	Route route(routeVec[0], routeVec[1], stops);

	return data[n] == route;
}

/*
	Adjacency List
*/
ADJList* smallADJList() {
	string airportData = "./data/smallairport.csv";
	string routeData = "./data/smallroutes.csv";

	vector<Airport> vertices = ImportAirports(airportData);
	vector<Route> edges = ImportRoutes(routeData);

	ADJList* graphList = new ADJList();
	graphList->addVertex(vertices);
	for (size_t i = 0; i < edges.size(); i++) {
		graphList->addEdge(edges[i]);
	}
	return graphList;
}

ADJList* fullADJList()
{
	string airportData = "./data/airports.csv";
	string routeData = "./data/routes.csv";

	vector<Airport> vertices = ImportAirports(airportData);
	vector<Route> edges = ImportRoutes(routeData);

	ADJList* graphList = new ADJList();
	graphList->addVertex(vertices);
	for (size_t i = 0; i < edges.size(); i++) {
		if (i >= 170)
		{
			int x = 0;
			x++;
		}
		graphList->addEdge(edges[i]);
	}
	return graphList;
}

/*
	PNG Airport tests
*/
//Compare the first 1, 10, 100, or 1000 airports in the dataset with
//the expected output
bool PngAirportComparison(int n)
{
	if(n < 5) n = 1;
	else if(n < 50) n = 10;
	else if(n < 500) n = 100;
	else n = 1000;

	vector<Airport> airports = ImportAirports("./data/airports.csv");
	vector<Airport> subAirports;
	for(int i = 0; i < n; ++i) subAirports.push_back(airports[i]);

	string folder = "./testPNGs/";
	string output = folder + "airportComparison" + to_string(n) + ".png";
	PngMap airportMap(subAirports);
	airportMap.createMap(vector<Route>(), output);

	PNG actual;
	actual.readFromFile(output);
	
	switch(n)
	{
		case 1:
		{
			PNG test;
			test.readFromFile(folder + "test1Airports.png");

			return test == actual;
		}
		
		case 10:
		{
			PNG test;
			test.readFromFile(folder + "test10Airports.png");

			return test == actual;
		}
		
		case 100:
		{
			PNG test;
			test.readFromFile(folder + "test100Airports.png");

			return test == actual;
		}

		case 1000:
		{
			PNG test;
			test.readFromFile(folder + "test1000Airports.png");

			return test == actual;
		}
	}

	return false;
}

/*
	Route Rendering
*/
//Compare the first 1, 10, 100, or 1000 routes in the dataset with
//the expected output
bool PngRouteComparison(int n)
{
	if(n < 5) n = 1;
	else if(n < 50) n = 10;
	else if(n < 500) n = 100;
	else n = 1000;

	vector<Airport> airports = ImportAirports("./data/airports.csv");
	vector<Route> routes = ImportRoutes("./data/routes.csv");
	vector<Route> subRoutes;
	for(int i = 0; i < n; ++i) subRoutes.push_back(routes[i]);

	string folder = "./testPNGs/";
	string output = folder + "routeComparison" + to_string(n) + ".png";
	PngMap routeMap(airports);
	routeMap.createMap(subRoutes, output);

	PNG actual;
	PNG test;
	actual.readFromFile(output);
	
	switch(n)
	{
		case 1:
		{
			test.readFromFile(folder + "test1Routes.png");
			return test == actual;
		}
		
		case 10:
		{
			test.readFromFile(folder + "test10Routes.png");
			return test == actual;
		}
		
		case 100:
		{
			test.readFromFile(folder + "test100Routes.png");
			return test == actual;
		}

		case 1000:
		{
			test.readFromFile(folder + "test1000Routes.png");
			return test == actual;
		}
	}

	return false;
}

/*
	Graph Coloring
*/
//Calculate a route between two nearby airports and compare the output
//with the expected output image.
bool PngSimpleRouteHighlightTest()
{
	Airport source, dest;
	source.name = "Hudson Bay Airport";
	source.city = "Hudson Bay";
	source.country = "Canada";
	source.code = "YHB";
	source.latitude = 52.81669998;
	source.longitude = -102.310997;

	dest.name = "Dryden Regional Airport";
	dest.city = "Dryden";
	dest.country = "Canada";
	dest.code = "YHD";
	dest.latitude = 49.831699;
	dest.longitude = -92.744202;
	
	ADJList* graph = fullADJList();

	BFS bfs(graph, source);
	vector<Airport> path = bfs.Shortest(graph, source, dest);

	PngMap pngMap(path);
	pngMap.createMap(vector<Route>(), "./testPNGs/simpleHighlightTest.png");
	
	return false;
}

//Calculate a route between two airports that are not nearby and compare the
//output with the epected output.
bool PngComplexRouteHighlightTest()
{
	Airport source, dest;
	source.name = "Hudson Bay Airport";
	source.city = "Hudson Bay";
	source.country = "Canada";
	source.code = "YHB";
	source.latitude = 52.81669998;
	source.longitude = -102.310997;

	dest.name = "Alexander Bay Airport";
	dest.city = "Alexander Bay";
	dest.country = "South Africa";
	dest.code = "ALJ";
	dest.latitude = -28.575001;
	dest.longitude = 16.5333;
	
	ADJList* graph = fullADJList();

	BFS bfs(graph, source);
	vector<Airport> path = bfs.Shortest(graph, source, dest);

	PngMap pngMap(path);
	pngMap.createMap(vector<Route>(), "./testPNGs/complexHighlightTest.png");
	
	return false;
}