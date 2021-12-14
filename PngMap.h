#pragma once

#include "Airport.h"
#include "Route.h"
#include "cs225/PNG.h"

#include <map>
#include <vector>

using std::map;
using std::make_pair;
using cs225::PNG;
using cs225::HSLAPixel;
using std::vector;
using std::pair;

class PngMap
{
private:
    //Four default values for the dots and lines plotted on the map
    HSLAPixel airportDot; //yellow
    HSLAPixel optimalRoute; //green

    //A mapping from an airport's code to the airport
    map<string, Airport> airports;
    PNG output;

public:
    PngMap(const vector<Airport>& airportList);

    //Generate the map with the two helper functions and save it
    void createMap(vector<Route> routes, string filename);

private:
    //Helper function for plotting airports
    void plotAirports();
    //Helper function for plotting route lines
    void plotRoutes(vector<Route> routes);
};