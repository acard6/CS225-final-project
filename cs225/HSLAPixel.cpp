/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {

    //Default constructor to initialize the class.
    HSLAPixel::HSLAPixel() {
        l = 1.0;
        a = 1.0;
    }

    //Constructor to initialize hue, saturation, and luminance.
    //Alpha is defaulted to 1 (opaque).
    HSLAPixel::HSLAPixel(double hue,
                            double saturation,
                            double luminance) {
        h = CheckHueRange(hue);
        s = CheckSatLumAlpRange(saturation);
        l = CheckSatLumAlpRange(luminance);
        a = 1.0;
    }

    //Constructor to initialize hue, saturation, luminance, and alpha.
    HSLAPixel::HSLAPixel(double hue,
                            double saturation,
                            double luminance,
                            double alpha) {
        h = CheckHueRange(hue);
        s = CheckSatLumAlpRange(saturation);
        l = CheckSatLumAlpRange(luminance);
        a = CheckSatLumAlpRange(alpha);
    }

    //Check the value given is within the hue range of [0, 360)
    double HSLAPixel::CheckHueRange(double val) {
        if(val >= 360.0) return 359.9;
        if(val < 0.0) return 0.0;
        return val;
    }

    //Check the value given is within the saturation, luminance,
    //and alpha range of [0, 1]
    double HSLAPixel::CheckSatLumAlpRange(double val) {
        if(val > 1.0) return 1.0;
        if(val < 0.0) return 0.0;
        return val;
    }
}
