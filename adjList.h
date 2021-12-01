#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <cstdlib>

#include "DataImport.h"
#include "Airport.h"
#include "Route.h"

using namespace std;

class ADJList{
    /**
     * Adjacency list
     */
    
    private:
        struct adjVert{
            string vertex;
            adjVert* next; 
        };
        struct edge{
            string start, end;
            int weight;
        }

        vector<string> list;
        double radius; //earths in miles
        double toRad; // multiplier conversion from degrees to radians 

    public:
        /** adds the edges that each airport is connected to 
        *   and the edge weight 
        */
        void addEdge(Airport::Airrport airport, Route::Route route);

        /**
         * calcultes how far each connected airport is from eachother
         * using haversine function to calculate great circle distance
         * https://en.wikipedia.org/wiki/Haversine_formula 
         */
        double distance (Airport::Airport air1, Airport::Airport air2);

};
