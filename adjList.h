#pragma once

#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <cstdlib>

#include "DataImport.h"

using namespace std;

class ADJList{
    /**
     * Adjacency list
     */
    
    private:
        /** 
        *   using a hash table to store the airport ID'd in a searchable way
        *   with the keys are the vertices as an airport loation and values as
        *   a linked list of the edges to adjecent vertecies containing
        *   
        *   from there
        */
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

        //pair of doubly liked airport and linked edges 
        std::pair<string, edgeList>** list;
        size_t size;
        double radius; //earths in kilometers
        double toRad; // multiplier conversion from degrees to radians 

        /**
         * hash function for so that airports are easy to look for and
         * so that fins doesnt take O(n^2)
         */
        unsigned int hashFunc(const Airport& airport);

        unsigned int hashFunc(const string& airport);

        //double hash function to help deal with collisions
        unsigned int doubleHash(const Airport& name);

        unsigned int doubleHash(const string& name);
        
        /**
         * uses hash function to help locate where in the table an
         * airport is
         */
        unsigned int find(const string& Name) const;

        /**
         * calcultes how far each connected airport is from eachother
         * using haversine function to calculate great circle distance
         * https://en.wikipedia.org/wiki/Haversine_formula 
         */
        double distance (const Airport& air1, const Airport& air2) const;

    public:
        /** adds the edges that each airport is connected to 
        *   and the edge weight 
        */
        
        /** 
         * default constructor for the graph
         * uses a doubly lined list as a hashtable.
         * used code from dhhashtable from lab_hash
         */
        ADJList();

        //add an edge to an existing vertext
        void addEdge(const Route& route);

        //adds a vertext to the hash table
        void addVertex(vector<Airport>& airportList);

        edgeList getList(Airport& airport);

};
