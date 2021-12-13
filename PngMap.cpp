#include "PngMap.h"

void drawLine(vector<pair<int, int>>& points, double start,
                double end, double slope, double intercept)
{
    for (double i = start; i < end; i += 0.1)
    {
        points.push_back({ i, slope * i + intercept });
    }
}

PngMap::PngMap(const vector<Airport>& airportList)
{
    for(auto a : airportList) airports.insert(make_pair(a.code, a));

    output.readFromFile("map.png");

    airportDot = HSLAPixel(0, 1, .50, 1); //yellow
    optimalRoute = HSLAPixel(104, 1, .50, 1); //green
    secondBestRoute = HSLAPixel(181, 1, .50, 1); //blue
    worstRoute = HSLAPixel(0, 1, .50, 1); //red
}

void PngMap::createMap(vector<Route> routes, string filename)
{
    plotAirports();
    plotRoutes(routes);

    output.writeToFile(filename);
}

void PngMap::plotAirports()
{
    for(auto a : airports)
    {
        Airport airport = a.second;

        double size = 2.0;

        double lat = airport.latitude / 90.0;
        double lon = airport.longitude / 180.0;

        double x = (1.0 + lon) * double(output.width()) / 2.0;
        double y = (1.0 - lat) * double(output.height()) / 2.0;

        for(double i = x; i < x + size; ++i)
        {
            for(double j = y; j < y + size; ++j)
            {
                output.getPixel(i, j) = airportDot;
            }
        }
    }
}

void PngMap::plotRoutes(vector<Route> routes)
{
    if(routes.empty()) return;
    
    for(int i = 0; i < routes.size(); ++i)
    {
        Airport source = airports[routes[i].source];
        Airport dest = airports[routes[i].destination];

        source.latitude /= 90.0;
        source.longitude /= 180.0;
        dest.latitude /= 90.0;
        dest.longitude /= 180.0;

        double sourceX = (1.0 + source.longitude) * double(output.width()) / 2.0;
        double sourceY = (1.0 - source.latitude) * double(output.height()) / 2.0;
        double destX = (1.0 + dest.longitude) * double(output.width()) / 2.0;
        double destY = (1.0 - dest.latitude) * double(output.height()) / 2.0;

        double slope = (sourceY - destY) / (sourceX - destX);
        double intercept = sourceY - sourceX * slope;

        vector<pair<int, int>> points;

        double start = (sourceX <= destX) ? sourceX : destX;
        double end = 0.0;

        if (start == sourceX) end = destX;
        else end = sourceX;

        drawLine(points, start, end, slope, intercept);

        for(auto p : points)
        {
            output.getPixel(p.first, p.second) = optimalRoute;
        }
    }
}