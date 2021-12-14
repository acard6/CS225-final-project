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


        size_t length;    //size of the list

        /**
         * hash function for so that airports are easy to look for and
         * so that fins doesnt take O(n^2)
         */
        unsigned int hashFunc(const Airport& airport);

        unsigned int hashFunc(const string& name);

        //double hash function to help deal with collisions
        unsigned int doubleHash(const Airport& Airport);

        unsigned int doubleHash(const string& name);

        /**
         * calcultes how far each connected airport is from eachother
         * using haversine function to calculate great circle distance
         * https://en.wikipedia.org/wiki/Haversine_formula 
         */
        double distance(const Airport& air1, const Airport& air2) const;        

    public:
        /** adds the edges that each airport is connected to 
        *   and the edge weight 
        */
        
        struct edge {
            Airport destination; // the airport thats connected to the head/key
            edge* next; //edge pointer pointing to another aiport that connects to the vertex
            double weight; //weight from key vertex to this edge
        };
        class edgeList {
            private:
                edge* head; //head is main/original airport/vertex
                int size;
            public:
                edgeList(){
                    head = NULL;
                    size = 1; 
                }
                edge* getHead(){return head;}
                int getSize(){return size;}
                void inc(){size +=1;}
                void header(edge newHead)
                {
                    head = new edge();
                    *head = newHead;
                }
        };

        /** 
         * default constructor for the graph
         * uses a doubly lined list as a hashtable.
         * used code from dhhashtable from lab_hash
         */
        ADJList();

        /**
         * uses hash function to help locate where in the table an
         * airport is
         */
        int find(const string& Name) const;

        //add an edge to an existing vertext
        void addEdge(const Route& route);

        //adds a vertext to the hash table
        void addVertex(vector<Airport>& airportList);

        //gets the size of the list
        size_t size();

        //for finding things at an index in the class
        edgeList operator[](const int& key);

        /**
         * uses hash function to help locate where in the table an
         * airport is
         */
        int find(string Name);

        edgeList getList(Airport& airport);
        edgeList getList(string& Name);

        /** pair of doubly liked airport and linked edges */ 
        std::pair<string, edgeList>** list;  
};
