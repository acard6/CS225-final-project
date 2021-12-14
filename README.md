# sarobin2-acard6-ob5-jgharib2
## Final project for sarobin2-acard6-ob5-jgharib2

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

###### PNG Comparison

For the airport output test, choose 1, 10, 100, or 1000 and call
PngAirportComparison(n). Only these numbers will work for the test. All
other numbers will be rounded to the nearest one of the four. The function
returns true if the output PNG is exactly the same as the test PNG and
false otherwise.

Similarly, the route output test operates the same. Choose 1, 10, 100, or
1000 and call PngRouteComparison(n). The function returns true if the output
PNG is exactly the same as the test PNG and false otherwise.