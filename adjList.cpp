#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>

#include "adjList.h"

using namespace std;

void ADJList::addEdge(Airport airport, Route route){
    
}

double ADJList::distance(Airport air1, Airport air2){
	
	int EarthRadiusKm = 6371;

	double toRad = M_PI / 180.0;
	double latRad1 = air1.latitude * toRad;
	double latRad2 = air2.latitude * toRad;
	double lonRad1 = air1.longitude * toRad;
	double lonRad2 = air2.longitude * toRad;

	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;

	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * EarthRadiusKm * computation;
}