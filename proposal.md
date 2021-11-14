Project Poposal

Leading question:

    Given a set of known flight paths

Dataset Acquisition and Processing:

    Acquisition
        For out dataset we will be using OpenFlights (https://openflights.org/data.html) mainly focusing on the route path data along with the airport location data. This data will lead our verticies to be airports/stops made and the edges to be the flight path between 

    Processing
        In terms of processing the dataset we will download the data file (.CSV) containing the flight paths from the OpenFlighst dataset stoting the data in an adjacency list for optimal runtime. From this list we will determine the optimal route from a chosen  point to another.

Graph Algorithms:
    Data Algorithms           
        Shortest path - Develop an algorithm that will find the shortest path between two given points in the set using Dijkstra's and Floyd–Warshall algorithms for comparison. The Input would be a set of flight paths and the output would be all possible shortest paths between the chosen two points. The expected runtime of this algoritm is
        
        Graph coloring - Develop an algorithm that colors the edges of the output such that the shortest path is highlighted and every other path is colored by determing how much of an increase it is from the shortest path by a given tolerence. Input will be a set of flight paths, and the output would be a graph with edges colored to visualize the optimal paths. The expected runtime of this graph coloring algorithm is O(V^2+E).


    Traversal Algorithms
        The main traversal algorithm will be a Breadth-first search. Where the input would be a the set of flight paths and the output would find the spanning set from one point to another. The output will also have appropriated edge coloring representing the shortest path between two chosen points. The expected runtime of a BFS traversal sould be O(V+E), where V is the number of vertices and E is the number of edges.



Timeline:
    Week 1: Data collection and process
        Complete and submit the team contract and initial project proposal. No real work can be done till project is approved.
 
    Week 2: Revision and 
       	Team members will tackle the development of the shortest route algorithms and graph coloring algorithms. 
 
    Week 3: Off (Fall break)
 
    Week 4: A* Development and Testing
       	The A* algorithm will be implemented once the overall structure of the graph is completed. Team members will also write test cases to thoroughly test the code in various aspects. Past tests will be improved upon and cleaned.
 
    Week 5: Zazz
       	Polish off any components and add face lighting if time is available.


Signatures:

Sasha Bilenkyi
