output: adjList.o Airport.o BFS.o DataImport.o main.o PngMap.o Route.o TestSuite.o HSLAPixel.o PNG.o lodepng.o
	g++ adjList.o Airport.o BFS.o DataImport.o main.o PngMap.o Route.o TestSuite.o HSLAPixel.o PNG.o lodepng.o -o project

adjList.o: adjList.cpp adjList.h
	g++ -std=c++11 -c adjList.cpp

Airport.o: Airport.cpp Airport.h
	g++ -std=c++11 -c Airport.cpp

BFS.o: BFS.o BFS.h
	g++ -std=c++11 -c BFS.cpp

DataImport.o: DataImport.cpp DataImport.h
	g++ -std=c++11 -c DataImport.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Map.o: PngMap.cpp PngMap.h
	g++ -std=c++11 -c PngMap.cpp

Route.o: Route.cpp Route.h
	g++ -std=c++11 -c Route.cpp

TestSuite.o: TestSuite.cpp TestSuite.h
	g++ -std=c++11 -c TestSuite.cpp

HSLAPixel.o: HSLAPixel.cpp HSLAPixel.h
	g++ -std=c++11 -c HSLAPixel.cpp

PNG.o: PNG.cpp PNG.h
	g++ -std=c++11 -c PNG.cpp

lodepng.o: lodepng.cpp lodepng.h
	g++ -std=c++11 -c lodepng.cpp

clean:
	rm *.o project