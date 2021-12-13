#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "adjList.h"


class BFS{
public:
  //Traverses the graph
  BFS(const Airport & start);
  //Uses Dijkstra's Algorithm to find the shortest path to every node
  vector<Airport> Shortest(Airport a, Airport b);

private:
  std::queue<Airport> queue_;
  Airport start_;
  std::vector<bool> visited;
};

#include "BFS.cpp"