//Process.h
#ifndef CHAOS_IMAGE_INCLUDE_PROCESS_H
#define CHAOS_IMAGE_INCLUDE_PROCESS_H

#include "Image.h"

namespace chaos {

namespace image {

class Image;
Image loadImage(const char* imgPath);

bool saveImage(const char* imgPath, const Image& img);


}//namespace image

}  //namespace chaos

#endif