#include "Route.h"

Route::Route() : source(""), destination(""), stops(0);

Route::Route(string source, string destination, int stops) :
                source(source), destination(destination), stops(stops) {}

bool Route::operator==(const Route& rhs)
{
    return source == rhs.source &&
            destination == rhs.destination &&
            stops == rhs.stops;
}