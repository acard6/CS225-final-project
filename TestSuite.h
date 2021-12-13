#pragma once

#include "Airport.h"
#include "DataImport.h"
#include "Route.h"
#include "adjList.h"
#include "Map.h"

/*
	Data import
*/
//Compare the nth value in the dataset to the test airport
bool TestAirportImport(int n, Airport* airport);

//Compare the nth value in the dataset to the test route
bool TestRouteImport(int n, Route* route);

/*
	PNG Airport tests
*/
//Compare the first 1, 10, 100, and 1000 airports to the plotted values
bool PngAirportComparison(int n);

/*
	Adjacency List
*/

void smallADJList();

/*
	Route Rendering
*/
bool PngAirportComparison();

/*
	Graph Coloring
*/
bool PngSimpleRouteHighlightComparison(Airport source, Airport dest);
bool PngComplexRouteHighlightComparison(Airport source, Airport dest);