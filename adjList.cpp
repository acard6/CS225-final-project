#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

#include "adjList.h"

using namespace std;

ADJList::adjList(){
	size = 7699;
	list = new std::pair<string,edgeList>* [size]
	for (size_t i=0; i<size; i++){
		list[i] = NULL;
	}
}

void ADJList::addEdge(const Route& route){
	string orig = route[0];
	string dest = route[1];
	unsigned int ogIdx = find(orig);
	unsigned int destIdx = find(dest);
	if (ogIdx != -1 || destIdx != -1){ // if either airport is in the hashtable
		Airport start = list[ogIdx]->second.head->destination;
		Airport end = list[destIdx]->second.head->destination;

		double length = distance(start, end);
		edge* endPoint = new edge();
		endPoint->destination = end;
		endPoint->weight = length;
		endPoint->next = NULL;

		edge* temp = list[ogIdx]->second.head;
		while (temp->next != NULL){
			//ensures that duplicate paths aren't added in
			if (temp->destination == endPoint->destination){return;}
			temp = temp->next;
		}
		if (temp->destination == endPoint->destination){return;}
		temp->next = endPoint;
	}
}

void ADJList::addVertex(vector<Airport>& airpotList){
	for (int i=0; i < airpotList.size(); i++){
		int idx = hashFunc(airportList[i]);
		int id2 = doubleHash(airportList[i]);
		while (list[idx] != NULL){
			idx = (idx + id2) % size;
		}
	
		edge* origin = new edge();
		origint->destination = airportList[i]; // this is the origin airport
		origin->weight = 0;
		origin->next = NULL; 
		edgeList linkedList = edgeList();
		linkedList.head = origin;
		list[idx] = new pair<string, edgeList>(airportList[i].name, origin);
	}
}

unsigned int ADJList::find(const string& name) const{
	unsigned int idx = hashFunc(name);
	unsigned int id2 = doublehash(name);
	unsigned int original = idx;
	bool should_probe = true;
	while (should_probe){
		if (list[idx] != NULL && list[idx]->first == name.name){
			return idx;
		}
		idx = (idx + id2) % size;
		if (idx == original){
			break;
		}
	}
	return -1;	
}

unsigned int ADJList::hashFunc(const Airport& airport){
	string name = airport.name;
	unsigned int h = 0;
	//int index = (int)name[0]*676+(int)name[1]*26+(int)name[2]-45695;
	//index = index % list.size();
	for (size_t i=0; i<name.length(); ++i){
		h = 33 * h + name[i];
	}
	return h % list->size();
}

unsigned int ADJList::doubleHash(const Airport& airport){
	string name = airport.name;
	unsigned int h = 5381;
	for (size_t i=0; i<name.length(); ++i){
		h = 31* h + name[i];
	}
	return (h % (list->size() - 1)) + 1;
}

unsigned int ADJList::hashFunc(const string& name){
	unsigned int h = 0;
	//int index = (int)name[0]*676+(int)name[1]*26+(int)name[2]-45695;
	//index = index % list.size();
	for (size_t i=0; i<name.length(); ++i){
		h = 33 * h + name[i];
	}
	return h % list->size();
}

unsigned int ADJList::doubleHash(const string& name){
	unsigned int h = 5381;
	for (size_t i=0; i<name.length(); ++i){
		h = 31* h + name[i];
	}
	return (h % (list->size() - 1)) + 1;
}

double ADJList::distance(Airport& air1, Airport& air2) const{
	
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