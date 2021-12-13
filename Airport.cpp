#include "Airport.h"

Airport::Airport() : name(""), city(""), country(""), code(""),
                        latitude(0.0), longitude(0.0) {}

Airport::Airport(string name, string city, string country, string code,
                    double latitude, double longitude) :
                    name(name), city(city), country(country), code(code),
                    latitude(latitude), longitude(longitude) {}

Airport::operator==(const Airport& rhs)
{
    return name == rhs.name &&
            city == rhs.city &&
            country == rhs.country &&
            code == rhs.code &&
            latitude == rhs.latitude &&
            longitude == rhs.longitude;
}