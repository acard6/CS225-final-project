## Introduction

We desired to understand if one could build a graph on top of a map using airports
around the world as vertices, and the routes between them as edges. Lesser goals
were also planned for. Such as rendering the airports and routes on a PNG map of
the Earth, and highlighting the shortest path between two airports. Though the
major goal of this project was not achieved, the process and algorithms are
detailed below. The goal of rendering was achieved and the highlighting of the
shortest path between two airports has been shown to work as a proof of concept.

###### ADJList

The core methodology used to build the graph is the adjacency list. In adjList.h and
adjList.cpp, this data structure uses a list of edges to store each vertice and it's
corresponding edges. The algorithm uses hashing to uniquely store the airports in
a linked list of pairs of strings and edge lists by hashing the airport's 3 character
code. The data structure is capable of outputting a list of edges based on an airport
code or index.

###### BFS

Breadth-first searching is used to probe the adjacency list. Specifically, Dijkstra's
algorithm generates a vector of airports from the desired source to the desired
destination. To do this, it stores a queue of airports that need to be probed for their
edges and a vector of booleans corresponding to the index of the vertex to mark if it
has been visited or not. This data structure does not currently work properly.

###### Airport and Route

There are two data structures that are used to store the airport and route information.
They are aptly named Airport and Route and stored in airport.h and airport.cpp, and 
route.h and route.cpp respectively. Although there is not much to these classes, they
are important for being able to quickly access the necessary information about which
they hold.

###### DataImport

To properly build the classes, dataimport.h and dataimport.cpp houses four purpose
built functions that import data from the appropriate csv documents and outputs vectors
of the corresponding classes.

###### PngMap

Outputting the data structure onto a PNG map of the Earth is handled by pngmap.h and
pngmap.cpp. The data structure uses the PNG and HSLAPixel classes generated in class
to store the background of the image, i.e., a 2D map of the Earth. It stores a C++
map from strings to airports and requires a vector of airports to be built. It creates
the output image by taking a vector of routes, using the source and destination
airports to find the appropriate airport information from the C++ map. It then plots
the latitude and longitude of the airports by mapping them into the pixel space of the
image. It plots the routes by calculating a line between the x and y pixels of the two
airports and then generating enough points between them to properly graph it onto the
image. Below are a couple images of the test output of 100 airports and 100 routes.

![](https://github-dev.cs.illinois.edu/cs225-fa21/sarobin2-acard6-ob5-jgharib2/blob/main/testPNGs/test100Airports.png)

![](https://github-dev.cs.illinois.edu/cs225-fa21/sarobin2-acard6-ob5-jgharib2/blob/main/testPNGs/test100Routes.png)

###### TestSuite

Testsuite.h is a group of functions that helps verify the functionality of the program.
The current tests in order are testing airport import and route import functionality,
testing the adjacency list against a subset and the full dataset, testing the output of
airports and routes on a map, and testing the routing output of a simple and complex
route. The last two do not currently work because the bfs class is not fully functioning.

## Discussion

###### Discoveries

The discoveries made were that it is possible to semi-accurately plot airports and routes
onto a 2D evenly spaced map of the Earth, as well as highlight routes between any two
airports. The routing has not been verified to work on the graph, but it is possible to
build an example vector of airports that are an actual route between the first and the
last in the vector, though this process is manual and tedious.

###### Pitfalls

The main issues that we encountered during development were dealing with the bfs and
adjacency list classes as they were clearly the more difficult. Such as it is, the
theory that they work is entirely there. The adjacency list is currently functioning
as expected, but the bfs class is not. There was a large issue with the adjacency
list that took a long time to track down. It was that there existed several routes
in the data file that included airports that are not in the airport dataset. Once
this was discovered, they were manually removed using Microsoft Excel. After which,
the adjacency list worked perfectly well.