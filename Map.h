#include "Airport.h"
#include "Route.h"
#include "cs225/PNG.h"

#include <map>

using std::map;
using std::make_pair;
using cs225::PNG;
using cs225::HSLAPixel;

class Map
{
    private:
        //Four default values for the dots and lines plotted on the map
        HSLAPixel airportDot(300, 1, .50, 1); //yellow
        HSLAPixel optimalRoute(104, 1, .50, 1); //green
        HSLAPixel secondBestRoute(181, 1, .50, 1); //blue
        HSLAPixel worstRoute(0, 1, .50, 1); //red

        //A mapping from an airport's code to the airport
        map<string, Airport> airports;
        PNG map;
    
    public:
        Map(const vector<Airport>& airportList);

        //Generate the map with the two helper functions and save it
        void createMap(vector<Route> routes, string filename);
    
    private:
        //Helper function for plotting airports
        void plotAirports();
        //Helper function for plotting route lines
        void plotRoutes(vector<Route> routes);
}