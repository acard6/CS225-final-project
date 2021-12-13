#pragma once

<<<<<<< HEAD
#include <string>
#include <vector>
#include <iostream>

=======
>>>>>>> 5cf3d4db78c6952f155cb787857be8a827836cbc
#include "Airport.h"
#include "DataImport.h"
#include "Route.h"
#include "adjList.h"

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