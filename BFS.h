#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "adjList.h"

using namespace std;


class BFS{
public:
  //Traverses the graph using BFS
  BFS(){}
  BFS(ADJList* graph,Airport start);
  //Uses Dijkstra's Algorithm to find the shortest path between two Airports
  vector<Airport> Shortest(ADJList* graph,Airport a, Airport b);

private:
  //Queue to store airports before probing their edges
  queue<Airport> queue_;

  //Vector of booleans corresponding to the visited edges
  vector<bool> visited;
};

