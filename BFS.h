#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "adjList.h"


class BFS{
public:
  //Traverses the graph
  vector<Airport> BFS(const Airport & start);
  //Uses Dijkstra's Algorithm to find the shortest path to every node
  vector<Airport> Shortest(Airport a);

private:
  std::queue<Airport> queue_;
  Airport start_;
  std::vector<bool> visited;
};