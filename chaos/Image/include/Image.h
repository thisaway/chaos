//Image.h
#ifndef CHAOS_IMAGE_INCLUDE_IMAGE_H
#define CHAOS_IMAGE_INCLUDE_IMAGE_H

#include "Def.h"
#include <cstddef>
#include <cassert>

namespace chaos {
namespace image {

class Image {
public:
  ~Image();
  Image() { }

  Image(const Image& img);
  Image(const size_t w, const size_t h, const size_t c);
  Image(const size_t w, const size_t h, const size_t c, const uint8_t* addr);

public:
  Image& operator=(const Image& img);
  inline uint8_t* data() const { return inData; }
  inline uint8_t* data() { return inData; }
  inline size_t width() const { return inWidth; }
  inline size_t height() const { return inHeight; }
  inline size_t channels() const { return inChannels; }

  inline uint8_t& operator()(size_t w, size_t h, size_t c) {

    assert(w < inWidth and h < inHeight and c < inChannels);
    return *(inData + h * inWidth * inChannels + w * inChannels + c);
  }

  inline uint8_t operator()(size_t w, size_t h, size_t c) const {

    assert(w < inWidth and h < inHeight and c < inChannels);
    return *(inData + h * inWidth * inChannels + w * inChannels + c);
  }

private:
  size_t inWidth;
  size_t inHeight;
  size_t inChannels;

private:
  uint8_t* inData;

};

}


}  //namespace chaos

#endif