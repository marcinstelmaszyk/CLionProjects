#include "Bitmap.h"

namespace btmap {

    Bitmap::Bitmap(int width, int height)
            : width(width), height(height),
              pPixels(new uint8_t[width*height*3]) {}

    bool Bitmap::write(std::string filename) {
        return false;
    }

    void Bitmap::setPixel(int x, int y,
            uint8_t red, uint8_t green, uint8_t blue) {

    }

}
