# sarobin2-acard6-ob5-jgharib2
## Final project for sarobin2-acard6-ob5-jgharib2

#### Data Format

###### Airports

Data is formatted in the following way in the CSV file:

Name,City,Country,Code,Latitude,Longitude

###### Routes

Data is formatted in the following way in the CSV file:

Source,Destination,Number of stops

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
The class that supports functionality for a breadth-first search on the
adjList class.

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

For the graph coloring test, call
PngSimpleRouteHighlightTest() or PngComplexRouteHighlightTest().
To call this, execute the program as normal with the argument
PngSimpleRouteHighlightTest() or PngComplexRouteHighlightTest()
The function returns TRUE if there were no errors, and FALSE if there were.

Output files are placed in the testPNGs folder with the naming convention
of ("simple" or "complex") + "HighlightTest.png"