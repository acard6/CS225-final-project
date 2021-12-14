#pragma once

#include <string>
#include <vector>

using std::vector;

#include "Airport.h"
#include "Route.h"

/*
    String split function is from the following stack overflow
    question from user RikuPotato:
    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
*/
vector<string> Split(string str, string delimiter);

/*
    Import a data file line by line into a vector so it can be
    read in by the airport or route import functions.
*/
vector<string> ImportDataFile(string filename);

/*
    Create a vector of strings from a filename and build the
    corresponding airport data structure for each line in the
    file.
*/
vector<Airport> ImportAirports(string filename);

/*
    Create a vector of strings from a filename and build the
    corresponding route data structure for each line in the
    file.
*/
vector<Route> ImportRoutes(string filename);