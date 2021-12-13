#define _USE_MATH_DEFINES

#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

#include "adjList.h"

using namespace std;

ADJList::ADJList(){
	length = 7699;
	list = new std::pair<string,edgeList>*[length];
	for (size_t i=0; i<length; i++){
		list[i] = NULL;
	}
}

size_t ADJList::size(){return length;}

pair<string,edgeList>& ADJList::operator[](const int& key){
    int idx = find(key);
    if (idx != -1) {return list[idx];} //returns the key which is a string
	else {return;}
}

ADJList::edgeList ADJList::getList(Airport& airport){
	string IDName = airport.name;
	unsigned int idx = find(IDName);
	if (idx != -1){
		return list[idx]->second;
	}
}

ADJList::edgeList ADJList::getList(string& Name){
	unsigned int idx = find(Name);
	if (idx != -1){
		return list[idx]->second;
	}
}

void ADJList::addEdge(const Route& route){
	string orig = route.source;
	string dest = route.destination;
	unsigned int ogIdx = find(orig);
	unsigned int destIdx = find(dest);
	if (ogIdx != -1 || destIdx != -1){ // if either airport is in the hashtable
		Airport start = list[ogIdx]->second.getHead()->destination;
		Airport end = list[destIdx]->second.getHead()->destination;

		double length = distance(start, end);
		edge* endPoint = new edge();
		endPoint->destination = end;
		endPoint->weight = length;
		endPoint->next = NULL;

		edge* temp = list[ogIdx]->second.getHead();
		while (temp->next != NULL){
			//ensures that duplicate paths aren't added in
			if (temp->destination.name == endPoint->destination.name){return;}
			temp = temp->next;
		}
		if (temp->destination.name == endPoint->destination.name){return;}
		temp->next = endPoint;
		list[ogIdx]->second.inc();
	}
}

void ADJList::addVertex(vector<Airport>& airportList){
	for (int i=0; i < airportList.size(); i++){
		int idx = hashFunc(airportList[i]);
		int id2 = doubleHash(airportList[i]);
		while (list[idx] != NULL){
			idx = (idx + id2) % length;
		}
	
		edge* origin = new edge();
		origin->destination = airportList[i]; // this is the origin airport
		origin->weight = 0;
		origin->next = NULL; 
		edgeList linkedList = edgeList();
		linkedList.header(*origin);
		list[idx] = new pair<string, edgeList>(airportList[i].name, linkedList);
	}
}

unsigned int ADJList::find(string Name){
	unsigned int idx = hashFunc(Name);
	unsigned int id2 = doubleHash(Name);
	unsigned int original = idx;
	bool should_probe = true;
	while (should_probe){
		if (list[idx] != NULL && list[idx]->first == Name){
			return idx;
		}
		idx = (idx + id2) % length;
		if (idx == original){
			break;
		}
	}
	return -1;	
}

unsigned int ADJList::hashFunc(const Airport& airport){
	string name = airport.name;
	hashFunc(name);
}

unsigned int ADJList::doubleHash(const Airport& airport){
	string name = airport.name;
	doubleHash(name);
}

unsigned int ADJList::hashFunc(const string& name){
	unsigned int h = 0;
	//int index = (int)name[0]*676+(int)name[1]*26+(int)name[2]-45695;
	//index = index % list.size();
	for (size_t i=0; i<name.length(); ++i){
		h = 33 * h + name[i];
	}
	return h % length;
}

unsigned int ADJList::doubleHash(const string& name){
	unsigned int h = 5381;
	for (size_t i=0; i<name.length(); ++i){
		h = 31* h + name[i];
	}
	return (h % (length - 1)) + 1;
}

double ADJList::distance(const Airport& air1, const Airport& air2) const{
  
	double radius = 6371; //earths in kilometers

	double toRad = M_PI / 180.0; // multiplier conversion from degrees to radians 
	double latRad1 = air1.latitude * toRad;
	double latRad2 = air2.latitude * toRad;
	double lonRad1 = air1.longitude * toRad;
	double lonRad2 = air2.longitude * toRad;

	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;

	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * radius * computation;
}