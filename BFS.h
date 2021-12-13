#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "Airport.h"
#include "adjList.h"

using namespace std;


class BFS{
public:
  //Traverses the graph
  BFS(const Airport & start);
  //Uses Dijkstra's Algorithm to find the shortest path to every node
  vector<Airport> Shortest(Airport a, Airport b);

private:
  queue<Airport> queue_;
  Airport start_;
  vector<bool> visited;
};

#include "BFS.cpp"
