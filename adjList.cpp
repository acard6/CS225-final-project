#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

#include "adjList.h"

using namespace std;

adjList::adjList(){
	size = 7699
	list = new pair<Airport,edge*>*[size]
	for (size_t i=0; i<size; i++){
		list[i] = NULL;
	}
}

void ADJList::addEdge(Airport airport, Route route){
    
}

void ADJList::addVertex(vector<Airport> airpotList){
	for (int i=0; i < airpotList.size(); i++){
		Airport place = airportList[i];
		int idx = hashFunc(place);
		int id2 = doubleHash(airportList[i])
		while list[idx] != NULL){
			idx = (idx + id2) % size;
		}
		list[idx] = new pair<place, NULL>;
	}
}

int ADJList::hashFunc(Airport airport){
	string name = airport.name;
	unsigned int h = 0;
	//int index = (int)name[0]*676+(int)name[1]*26+(int)name[2]-45695;
	//index = index % list.size();
	for (size_t i=0; i<name.length(); ++i)
		h = 33 * h + name[i];
	return h % list->size();
}

int ADJList::doubleHash(Airport airport){
	string name = airport.name;
	unsigned int h = 5381;
	for (size_t i=0; i<name.length(); ++i)
		h = 31* h + name[i];

	return (h % (list->size() - 1)) + 1;
}

int ADJList::find(Airport airport){
	int idx = hashFunc(airport);
	int id2 = doublehash(airport);
	int original = idx;
	while (list[idx]->first.name != airport.name){
		idx = (idx + id2) % size;
		if (idx == original){
			return -1;
		}
	}
	
	return idx;
}

double ADJList::distance(Airport air1, Airport air2){
	
	radius = 6371;

	toRad = M_PI / 180.0;
	double latRad1 = air1.latitude * toRad;
	double latRad2 = air2.latitude * toRad;
	double lonRad1 = air1.longitude * toRad;
	double lonRad2 = air2.longitude * toRad;

	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;

	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * radius * computation;
}