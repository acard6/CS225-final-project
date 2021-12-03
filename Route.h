#pragma once

#include <string>

using std::string;

class Route
{
    public:
        string source; //Source of the route
        string destination; //Route destination
        int stops; //Number of stops in the route
    
    public:
        Route(string source, string destination, int stops);
};