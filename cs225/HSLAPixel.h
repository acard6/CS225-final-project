/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {

    class HSLAPixel {
        public:
        HSLAPixel();
        HSLAPixel(double hue, double saturation, double luminance);
        HSLAPixel(double hue, double saturation, double luminance, double alpha);

        double h; //range = [0, 360)
        double s ; //range = [0, 1]
        double l; //range = [0, 1]
        double a; //range = [0, 1]

        double CheckHueRange(double val);
        double CheckSatLumAlpRange(double val);
    };
}
