//Process.cc
#include "Process.h"
#include <cstring>
#include <iostream>

#include "FreeImage.h"

namespace chaos {

namespace image {

static char const *imageFormat[] = {"bmp", "jpg", "jpeg", "png"};
static size_t imageFormatLength = 4;

static int parserImageFormat(const char* imgPath) {

    size_t i = 0;
    while(imgPath[i] != '\0') {
        if(imgPath[i] == '.') { 
            ++i; 
            break; 
        }
        ++i;
    }

    for(int index = 0; index < imageFormatLength; ++index) {
        if(strcmp(imageFormat[index], imgPath + i) == 0)
            return index;
    }

    return -1;
}

Image loadImage(const char* imgPath) {

    int formatId = parserImageFormat(imgPath);
    if(formatId == -1){
        std::cout << "[ERROR]:Image path," << imgPath << " is non-compliant." << std::endl;
        std::cout << std::endl;
        exit(-1);
    }

    FREE_IMAGE_FORMAT imgFormat;
    switch(formatId) {
        case 0: imgFormat = FIF_BMP; break;
        case 1: imgFormat = FIF_JPEG; break;
        case 2: imgFormat = FIF_JPEG; break;
        case 3: imgFormat = FIF_PNG; break;
    }

    FIBITMAP *img = FreeImage_Load(imgFormat, imgPath, BMP_DEFAULT);
    if(!img) {
        std::cout << "[Error]: May be image path, " << imgPath << " does't exsit." << std::endl;
        exit(-1);
    }

    unsigned width = FreeImage_GetWidth(img);
    unsigned height = FreeImage_GetHeight(img);
    unsigned channels = FreeImage_GetBPP(img)/8;
    BYTE *bits = (BYTE*)FreeImage_GetBits(img);

    Image retImg(width, height, channels, bits);

    FreeImage_Unload(img);

    return retImg;
}

bool saveImage(const char* imgPath, const Image& img) {

    int formatId = parserImageFormat(imgPath);
    if(formatId == -1){
        std::cout << "[ERROR]:Image path," << imgPath << " is non-compliant." << std::endl;
        std::cout << std::endl;
        return 0;
    }

    FIBITMAP *imgptr = FreeImage_Allocate(img.width(), img.height(), img.channels() * 8);
    if(!imgptr) {
        std::cout << "[Error]: Something is wrong in saveImage." << std::endl;
        FreeImage_Unload(imgptr);
        return 0;
    }
    BYTE *bits = (BYTE*)FreeImage_GetBits(imgptr);
    memcpy(bits, img.data(), sizeof(uint8_t) * img.width() * img.height() * img.channels());

    FREE_IMAGE_FORMAT imgFormat;
    switch(formatId) {
        case 0: imgFormat = FIF_BMP; break;
        case 1: imgFormat = FIF_JPEG; break;
        case 2: imgFormat = FIF_JPEG; break;
        case 3: imgFormat = FIF_PNG; break;
    }

    if (!FreeImage_Save(imgFormat, imgptr, imgPath, 0)) {
        std::cout << "[Error]: Something is wrong in saveImage." << std::endl;
        FreeImage_Unload(imgptr);
        return 0;
    }

    FreeImage_Unload(imgptr);

    return 1;
}

}

}