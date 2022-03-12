//Drawer.h
#ifndef CHAOS_IMAGE_INCLUDE_DRAWER_H
#define CHAOS_IMAGE_INCLUDE_DRAWER_H

#include "Conception2d.h"
#include "Color.h"

#include <cstddef>

namespace chaos {

namespace image {

class Image;
class Drawer {

public: 
  ~Drawer() { }
  Drawer() : color(red), thickness(1) { }
  Drawer(const Color& c, const size_t t)
    : color(c), thickness(t) { }

public:
  inline void setColor(const Color& c) { color = c; }
  inline void setThickness(const size_t t)  { thickness = t; }

public:
  bool drawLine(Image& img, const chaos::geo::Point2i& p1, const chaos::geo::Point2i& p2);
  
private:
  Color color;
  size_t thickness;
};

}

}

#endif