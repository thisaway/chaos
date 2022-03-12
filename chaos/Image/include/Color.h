//Color.h
#ifndef CHAOS_IMAGE_INCLUDE_COLOR_H
#define CHAOS_IMAGE_INCLUDE_COLOR_H

#include "Def.h"

namespace chaos {

namespace image {

struct Color {
    Color(): r(0), g(0), b(0) { }
    Color(uint8_t c1, uint8_t c2, uint8_t c3)
      : r(c1), g(c2), b(c3) { }
    
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

Color black(0, 0, 0);
Color white(255, 255, 255);
Color blue(255, 0, 0);
Color green(0, 255, 0);
Color red(0, 0, 255);

}

}

#endif