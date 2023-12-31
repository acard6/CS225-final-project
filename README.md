# sarobin2-acard6-ob5-jgharib2
## Final project for sarobin2-acard6-ob5-jgharib2

#### Project Presentation

https://illinois.zoom.us/rec/play/G4gbmXgGuXdBbKREoqJpp8Q_nNu-iNVu_oZ1rze5kc0bwV_N4Uf-PT3I7EwvqcQfoipS7-P5gT2UKN98.R9AtSdlI4YubKVIr?startTime=1639546372000&_x_zm_rtaid=CmgKdHQOTLqLxgsnmEAeEg.1639544180337.e13dd179658131b38488be3f4593de6f&_x_zm_rhtaid=891

#### Data Format

Data is found in the data folder. Loading it in requires you to change the
strings at the top of main.cpp.

###### Airports

Data is formatted in the following way in the CSV file:

Name,City,Country,Code,Latitude,Longitude

###### Routes

Data is formatted in the following way in the CSV file:

Source,Destination,Number of stops

#### Linkage

![This is an image](https://github-dev.cs.illinois.edu/cs225-fa21/sarobin2-acard6-ob5-jgharib2/blob/main/Report/diagram.png)

#### Code Base Layout

The main components of the project are included in the base of the
repository. The supplemental code, i.e., PNG, HSLAPixel, and lodepng are
located in the "cs225" folder.

###### adjList
A class that encapsulates the graph functionality in an adjacency list.

###### Airport
The class that holds the relevant information for each airport (name, city,
country, airport code, latitude, and longitude).

###### BFS
The class that supports functionality for a breadth-first search and
Dijkstra's Algorithm on the adjList class.

###### DataImport
A group of helper functions that import data from CSVs into vectors to be
used throughout the program.

###### PngMap
A class used to output a set or airports and routes on a 2D map of the Earth
using their latitude and longitude.

###### Route
The class that holds the relevant information for each route (source,
destination, and number of stops).

###### TestSuite
A group of functions used to test various aspects of the program.

#### Code Base Functionality

The executable can be run with ./project (arguments). There is no default
functionality in it. Arguments are needed to run the program.

###### Adjacency List arguments

###### Graph arguments

PlotFull (string filename)
PlotN (int n) (string filename)

###### Test arguments

TestArgs - test arguments are correctly being passed
TestAirportImport (int n) (string airportString)
TestRouteImport (int n) (string routeString)
PngAirportComparison (int n)
PngRouteComparison (int n)

#### Running test cases

###### Importing data

To test the airport import, pick a random line in the airport.csv datafile.
You'll want to open it in a program that counts the number of lines, because
you'll be taking the line number, subtracting one, and using it as n. To
test this, call the program as normal with the argument
TestAirportImport (line number - 1) (string in the chosen line)
The function will output TRUE if the airport objects are the same, and false
otherwise.

Similar to the airport import, to test the route import, choose a random
line in the routes.csv file and create a manual route object. To test this,
call the program as normal with the argument
TestRouteImport (line number - 1) (string in the chosen line)
The function will output TRUE if the airport objects are the same, and false
otherwise.

###### Adjacency List

To test the adjacency list, call adjList(). To call this, execute the program
as normal with the argument
adjList (3 letter airport code)
The function will output the name of the desired airport once it is found,
and -1 otherwise.

###### PNG Comparison

For the airport output test, choose 1, 10, 100, or 1000 and call
PngAirportComparison(n). Only these numbers will work for the test. All
other numbers will be rounded to the nearest one of the four. To call this,
execute the program as normal with the argument
PngAirportComparison (1, 10, 100, or 1000)
The function returns TRUE if the output PNG is exactly the same as the test
PNG and FALSE otherwise.

Similarly, the route output test operates the same. Choose 1, 10, 100, or
1000 and call PngRouteComparison(n). To call this, execute the program as
normal with the argument PngRouteComparison (1, 10, 100, or 1000)
The function returns TRUE if the output PNG is exactly the same as the test
PNG and FALSE otherwise.

Output files are placed in the testPNGs folder with the naming convention
of ("airport" or "route") + (n) + ".png"

###### Graph Coloring

**Currently does not work**

For the graph coloring test, call
PngSimpleRouteHighlightTest() or PngComplexRouteHighlightTest().
To call this, execute the program as normal with the argument
PngSimpleRouteHighlightTest() or PngComplexRouteHighlightTest()
The function returns TRUE if there were no errors, and FALSE if there were.

Output files are placed in the testPNGs folder with the naming convention
of ("simple" or "complex") + "HighlightTest.png"
