#include "adjList.h"
#include "cs225/PNG.h"
#include <iostream>
#include <map>
#include <random>

using namespace std;
using cs225::PNG;
using cs225::HSLAPixel;
using std::map;
using std::make_pair;

void drawLine(vector<pair<int, int>>& points, double start, double end, double slope, double intercept)
{
    for (double i = start; i < end; i += 0.1) points.push_back({ i, slope * i + intercept });
}

int main()
{
    string airportData = "./data/airports.csv";
    string routeData = "./data/routes.csv";

    vector<Airport> vertices = ImportAirports(airportData);
    vector<Route> edges = ImportRoutes(routeData);

    // the actual graph made from the adjacency list class
    ADJList::ADJList graphList;
    graphList.addVertex(vertices);
    for (int i=0; i<edges.size(); i++){
        graphList.addEdge(edge[i]);
    }

    map<string, Airport> airports;

    for (auto a : vertices)
    {
        airports.insert(make_pair(a.code, a));
    }

    PNG map;
    map.readFromFile("map.png");

    HSLAPixel airportDot(300, 1, .50, 1); //yellow
    HSLAPixel routePath(181, 1, .50, 1); //blue

    for (auto a : vertices)
    {
        double size = 2.0;

        double lat = a.latitude / 90.0;
        double lon = a.longitude / 180.0;

        double x = (1.0 + lon) * double(map.width()) / 2.0;
        double y = (1.0 - lat) * double(map.height()) / 2.0;

        for (double i = x; i < x + size; ++i)
        {
            for (double j = y; j < y + size; ++j)
            {
                map.getPixel(i, j) = airportDot;
            }
        }
    }

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, 10);

    for (int i = 0; i < 60000; i+=distr(generator))
    {
        Airport source = airports[edges[i].source];
        Airport dest = airports[edges[i].destination];

        source.latitude /= 90.0;
        source.longitude /= 180.0;
        dest.latitude /= 90.0;
        dest.longitude /= 180.0;

        double sourceX = (1.0 + source.longitude) * double(map.width()) / 2.0;
        double sourceY = (1.0 - source.latitude) * double(map.height()) / 2.0;
        double destX = (1.0 + dest.longitude) * double(map.width()) / 2.0;
        double destY = (1.0 - dest.latitude) * double(map.height()) / 2.0;

        double slope = (sourceY - destY) / (sourceX - destX);
        double intercept = sourceY - sourceX * slope;

        vector<pair<int, int>> points;

        double start = (sourceX <= destX) ? sourceX : destX;
        double end = 0.0;

        if (start == sourceX) end = destX;
        else end = sourceX;

        drawLine(points, start, end, slope, intercept);

        for (auto p : points) map.getPixel(p.first, p.second) = routePath;
    }

    map.writeToFile("test.png");

    return 0;
}