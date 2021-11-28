#include <fstream>

using std::ofstream;

#include "DataImport.h"

/*
    String split function is from the following stack overflow
    question from user RikuPotato:
    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
*/

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
}

vector<string> DataImport::ImportDataFile(string filename)
{
    ifstream data(filename);
    vector<string> output;

    if(data.is_open())
    {
        string temp = "";

        while(getline(data, temp))
        {
            output.push_back(temp);
            temp = "";
        }

        data.close()
    }

    return output;
}

vector<Airport> DataImport::ImportAirports(string filename)
{
    
}

vector<Route> DataImport::ImportRoutes(string filename)
{

}