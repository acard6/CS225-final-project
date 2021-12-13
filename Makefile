output: adjList.o Airport.o DataImport.o main.o Route.o TestSuite.o HSLAPixel.o PNG.o lodepng.o
	g++ adjList.o Airport.o DataImport.o main.o Route.o TestSuite.o HSLAPixel.o PNG.o lodepng.o -o project

adjList.o: adjList.cpp adjList.h
	g++ -c adjList.cpp

Airport.o: Airport.cpp Airport.h
	g++ -c Airport.cpp

DataImport.o: DataImport.cpp DataImport.h
	g++ -c DataImport.cpp

main.o: main.cpp
	g++ -c main.cpp

Route.o: Route.cpp Route.h
	g++ -c Route.cpp

TestSuite.o: TestSuite.cpp TestSuite.h
	g++ -c TestSuite.cpp

HSLAPixel.o: HSLAPixel.cpp HSLAPixel.h
	g++ -c HSLAPixel.cpp

PNG.o: PNG.cpp PNG.h
	g++ -c PNG.cpp

lodepng.o: lodepng.cpp lodepng.h
	g++ -c lodepng.cpp

clean:
	rm *.o project