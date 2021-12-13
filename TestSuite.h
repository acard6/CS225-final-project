#pragma once

#include <string>
#include <vector>

#include "Airport.h"
#include "Route.h"
#include "adjList.h"

/*
	Data import
*/
bool DataImportAtNTest(int n, string testString);

/*
	PNG Airport tests
*/
bool PngAirportComparison(int n);

/*
	Adjacency List
*/

bool smallADJListComparison();

/*
	Route Rendering
*/
bool PngAirportComparison(int n);

/*
	Graph Coloring
*/
bool PngSimpleRouteHighlightComparison(Airport source, Airport dest);
bool PngComplexRouteHighlightComparison(Airport source, Airport dest);