output: adjList.o Airport.o DataImport.o main.o Route.o TestSuite.o
	g++ adjList.o Airport.o DataImport.o main.o Route.o TestSuite.o -o project

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

clean:
	rm *.o project