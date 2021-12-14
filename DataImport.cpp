#include <fstream>
#include <string>

using std::ifstream;
//using std::strtod;
using namespace std;

#include "DataImport.h"

vector<string> Split(string str, string delimiter)
{
    vector<string> splitStrings;
    size_t pos = 0;

    while((pos = str.find(delimiter)) != string::npos)
    {
        string token = str.substr(0, pos);
        
        if(token.length() > 0) splitStrings.push_back(token);

        str.erase(0, pos + delimiter.length());
    }

    if(str.length() > 0) splitStrings.push_back(str);

    return splitStrings;
};

vector<string> ImportDataFile(string filename)
{
    ifstream data(filename);
    vector<string> output;

    if(data.is_open())
    {
        string temp = "";

        while(getline(data, temp))
        {
            while (temp[0] < 0) temp.erase(temp.begin());

            output.push_back(temp);
            temp = "";
        }

        data.close();
    }

    return output;
}

vector<Airport> ImportAirports(string filename)
{
    vector<Airport> airports;
    vector<string> inputData = ImportDataFile(filename);
    
    for (auto s : inputData)
    {
        vector<string> temp = Split(s, ",");

        //0 = name
        //1 = city
        //2 = country
        //3 = code
        //4 = latitude
        //5 = longitude

        if (airports.size() >= 3060)
        {
            int i = 0;
            ++i;
        }

        double lat = stod(temp[4].c_str(), NULL);
        double lon = strtod(temp[5].c_str(), NULL);

        Airport a(temp[0], temp[1], temp[2], temp[3], lat, lon);

        airports.push_back(a);
    }

    return airports;
}

vector<Route> ImportRoutes(string filename)
{
    vector<Route> routes;
    vector<string> inputData = ImportDataFile(filename);

    for (auto s : inputData)
    {
        vector<string> temp = Split(s, ",");

        //0 = source
        //1 = destination
        //2 = number of stops

        int stops = stoi(temp[2]);

        Route r(temp[0], temp[1], stops);

        routes.push_back(r);
    }

    return routes;
}