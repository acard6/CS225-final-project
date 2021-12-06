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
            Airport end; // airport connected to the key
            edge* next; //edge pointer pointing to another connected edge
            int weight; //weight from key to this edge
        };

        //pair of doubly liked airport and linked edges 
        std::pair<Airport,edge*>** list;
        size_t size;
        double radius; //earths in kilometers
        double toRad; // multiplier conversion from degrees to radians 

    public:
        /** adds the edges that each airport is connected to 
        *   and the edge weight 
        */
        
        /** 
         * default constructor for the graph
         * uses a doubly lined list as a hashtable.
         * used code from dhhashtable from lab_hash
         */
        adjList();

        //add an edge to an existing vertext
        void addEdge(Airport airport, Route route);

        //adds a vertext to the hash table
        void addVertex(vector<Airport> airportList);

        /**
         * hash function for so that airports are easy to look for and
         * so that fins doesnt take O(n^2)
         */
        int hashFunc(Airport airport);

        //double hash function to help deal with collisions
        int doubleHash(Airport airport)

        /**
         * uses hash function to help locate where in the table an
         * airport is
         */
        int find(Airport airport);

        /**
         * calcultes how far each connected airport is from eachother
         * using haversine function to calculate great circle distance
         * https://en.wikipedia.org/wiki/Haversine_formula 
         */
        double distance (Airport air1, Airport air2);

};
