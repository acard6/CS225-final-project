#include "DataImport.h"

int main()
{
    string airports = "./data/airports.dat";
    string routes = "./data/routes.dat";

    //DataImport::ImportDataFile(airports);
    //DataImport::ImportAirports(airports);
    DataImport::ImportRoutes(routes);

    return 0;
}