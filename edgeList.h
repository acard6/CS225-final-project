#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <cstdlib>

#include "DataImport.h"

struct edge {
    Airport destination; // the airport thats connected to the head/key 
    edge* next; //edge pointer pointing to another aiport that connects to the vertex
    double weight; //weight from key vertex to this edge
};
class edgeList {
    private:
        edge* head; //head is main/original airport/vertex
    public:
        edgeList(){
            head = NULL; 
        }
 };