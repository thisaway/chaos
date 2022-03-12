//Drawer.cc
#include "Drawer.h"
#include "Image.h"

namespace chaos {

namespace image {

//no thickness
bool Drawer::
drawLine(Image& img, const chaos::geo::Point2i& p1, const chaos::geo::Point2i& p2) {
    if(p1.z() == 0 or p2.z() == 0)
        return false;

    int p1x = p1.x() / p1.z();
    int p1y = p1.y() / p1.z();

    int p2x = p2.x() / p2.z();
    int p2y = p2.y() / p2.z();

    if(p1x < 0 or p1y < 0 or p2x < 0 or p2y < 0) 
        return false;
    if(p1x >= img.width() or p1y >= img.height() or p2x >= img.width() or p2y >= img.height())
        return false;

    int dx = p2x > p1x ? 1 : -1;
    int dy = (p2y - p1y) / (p2x - p1x);

    while(p1x <= p2x) {
        img(p1x, p1y, 0) = color.r;
        img(p1x, p1y, 1) = color.g;
        img(p1x, p1y, 2) = color.b;
        p1x += dx;
        p1y += dy;
    }

    return true;
}
}
}