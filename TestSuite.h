#pragma once

#include "Airport.h"
#include "DataImport.h"
#include "Route.h"

#include <iostream>

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
bool PngAirportComparison(int n);

/*
	Adjacency List
*/

/*
	Route Rendering
*/
bool PngAirportComparison(int n);

/*
	Graph Coloring
*/
bool PngSimpleRouteHighlightComparison(Airport source, Airport dest);
bool PngComplexRouteHighlightComparison(Airport source, Airport dest);