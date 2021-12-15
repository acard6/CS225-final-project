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
        *   using a hash table to store the airport ID's in a searchable way
        *   where the keys are the vertices as an airport code and values as
        *   a linked list of the edges adjecent to that vertecies
        *   
        */


        int length;    //size of the list
        
        /**
         * The following hash functions we imported and used from a previous
         * lab, lab_hash. The functoin implementaion was also heavily inspired
         * by the dhhastable .h and .cpp for a successful and fast graph
         */

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
        
        //edge struct that acts as nodes in the linked list
        struct edge {
            Airport destination; // the airport thats connected to the head/key
            edge* next; //edge pointer pointing to another aiport that connects to the vertex
            double weight; //weight from key vertex to this edge
        };

        //container for the linked list of edges
        class edgeList {
            private:
                edge* head; //head is main/original airport/vertex
                int size;  // the size of the linked list
            public:
                edgeList(){
                    head = NULL;
                    size = 1; 
                }
                edge* getHead(){return head;} // way of accessing the head of the list
                int getSize(){return size;} // way of accessing the size of the list
                void inc(){size +=1;} // increments the size of the list
                void header(edge newHead) // changes the head of the list
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
        int size();

        //for finding things at an index in the class
        edgeList operator[](const int& key);

        /**
         * uses hash function to help locate where in the table an
         * airport is
         */
        int find(string Name);
        
        //get the edgeList of a specified airport of Airport class
        edgeList getList(Airport& airport);

        //get the edgelist of a specified airport codeID name
        edgeList getList(string& Name);

        //gets the edgeList of a specified index
        edgeList getList(int index);

        /** pair of string and liked airport by linked edges */ 
        std::pair<string, edgeList>** list;  
};
