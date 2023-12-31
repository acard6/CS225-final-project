Project Poposal sarobin2-acard6-ob5-jgharib2

Leading question:

Given a set of known flight paths we want to be able to:

Find the shortest path between two chosen points
highlight all the shortest paths
Output that path onto a world map

Dataset Acquisition and Processing:

Acquisition

For out dataset we will be using OpenFlights (https://openflights.org/data.html) mainly focusing on the
route path data along with the airport location data. This data will lead our verticies to be
airports/stops made and the edges to be the flight path between.

Processing

In terms of processing the dataset we will download the data files (.CSV) containing the flight paths
and airport locations from the OpenFlighst dataset storing the data in an adjacency list for optimal
runtime. From this list we will determine the shortest route from a chosen point to another.

Graph Algorithms

Data Algorithms

Shortest path - Develop an algorithm that will find the shortest path between two given points in the
set using dijkstra's algorithm. The Input would the graph of flight paths and the output would be all
possible shortest paths between the chosen two points. For our shortest path algorithm the weighted
edges would be defined as the distance between two points on the surface of a sphere. In this case the
sphere is the globe of the earth. Distance will be found by using the Haversine formula to to determine
the weight of the edges. The expected runtime of this algoritm is O(E+Vlog(V)).
        
Graph coloring - Develop an algorithm that colors the edges of the output such that the shortest path is
highlighted. Input will be a set of flight paths, and the output would be a graph with
edges colored to visualize the optimal paths. The expected runtime of this graph coloring algorithm is
O(V^2+E).

Rendering - If time alloted, develop an algorithm that outputs the colored graph onto a world map. The
input would be the colored shortest path graph and the list of associated airports. The expected runtime
would be O(deg(V)).

Traversal Algorithms

The main travelral algorithm will be a Breadth-first search. Where the input would be  a the set of flight
paths and the output would find the spanning set from one point to another. The output will also have
appropriated edge coloring representing the shortest path between two chosen points. The expected runtime
of a BFS traversal sould be O(V+E), where V is the number of vertices and E is the number of edges.

Timeline:

Week 1: Data collection and process
Complete and submit the team contract and initial project proposal. No real work can be done till project is approved.
 
Week 2: Revision and shortest path algorithm
Team members will tackle the revising the proposal to better fit the project and develop the shortest path algorithms.
The first issue will be to address the corrections needed to make to the proposal to move the project forward. After
that, tasks can be split between processing data to make a graph via BFS traveral and a shortest path algorithm.

Week 2: Revision and 
Team members will tackle the development of the shortest route algorithms and graph coloring algorithms. 
 
Week 3: Off (Fall break)
 
Week 4: Graph coloring and rendering
The graph coloring algorithm and rendering will be implemented once the overall structure of the graph is completed.
Team members will also write test cases to thoroughly test the code in various aspects. Past tests will be improved upon
and cleaned.
 
Week 5: Zazz
Polish off any unfinished components and revise and add more test cases.


Signatures:

Sasha Bilenkyi
Alan Cardiel
Sean Womack
Justin Gharib
