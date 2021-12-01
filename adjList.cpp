#include <string>
#include <vector>
#include <cmath>

#include "adjList.h"

using namespace std;

void adjList::addEdge(Airport::Airport airport, Route::Route route){
    
}

double distance (Airport::Airport air1, Airport::Airport air2){

    radius = 3958.8;
    toRad = M_PI / 180;

    double lat1 = air1.latitude;
    double lat2 = air2.latitude;
    
    double dLat = (lat2 - lat1) * toRad;
    double dLong = (air2.longitude - air1.longitude) * toRad;

    double havsin = pow(sin(dLat/2),2) + cos(lat1)*cos(lat2)*pow(sin(dLong/2),2);
    double distance = 2*radius*asin(sqrt(havsin));

    return distance;
}