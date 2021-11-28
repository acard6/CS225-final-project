#include <string>

using std::string;

class Airport
{
    private:
        string name; //Name of the airport
        string city; //City in which the airport is
        string country; //Country in which the airport is
        string code; //3 letter alpha code for the airport
        double latitude; //Latitude of the airport
        double longitude; //Longitude of the airport
    
    public:
        Airport(string nname, string city, string country, string code,
                double latitude, double longitude);
};