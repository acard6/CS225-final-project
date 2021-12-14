#pragma once

#include <string>
#include <vector>

using std::vector;

#include "Airport.h"
#include "Route.h"

vector<string> Split(string str, string delimiter);
vector<string> ImportDataFile(string filename);
vector<Airport> ImportAirports(string filename);
vector<Route> ImportRoutes(string filename);