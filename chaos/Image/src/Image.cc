//Image.cc
#include "Image.h"

#include <cstring>
#include "Process.h"

namespace chaos {

namespace image {

Image::
~Image() {
    delete[] inData;
}

Image::
Image(const Image& img)
  : inWidth(img.width()), inHeight(img.height()), inChannels(img.channels()),  \
  inData(new uint8_t[inHeight * inWidth * inChannels]) {  //may be cause memory error:not enough storage.

    memcpy(inData, img.data(), sizeof(uint8_t) * inHeight * inWidth * inChannels);
}

Image::
Image(const size_t w, const size_t h, const size_t c) 
  : inWidth(w), inHeight(h), inChannels(c), inData(new uint8_t[inHeight * inWidth * inChannels]) {

      memset(inData, 255, sizeof(uint8_t) * inHeight * inWidth * inChannels);
}

Image::
Image(const size_t w, const size_t h, const size_t c, const uint8_t* addr) 
  : inWidth(w), inHeight(h), inChannels(c), inData(new uint8_t[inHeight * inWidth * inChannels]){

    memcpy(this->inData, addr, sizeof(uint8_t) * inHeight * inWidth * inChannels);
}

Image& Image::
operator=(const Image& img) {

    this->inWidth = img.width();
    this->inHeight = img.height();
    this->inChannels = img.channels();
    this->inData = new uint8_t[this->inWidth * this->inHeight * this->inChannels];
    memcpy(this->inData, img.data(), sizeof(uint8_t) * inHeight * inWidth * inChannels);

    return *this;
}

}

}