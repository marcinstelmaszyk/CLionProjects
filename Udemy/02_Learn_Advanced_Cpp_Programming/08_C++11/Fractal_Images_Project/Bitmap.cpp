#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace btmap {

    Bitmap::Bitmap(int width, int height)
            : width(width), height(height),
              pPixels(new uint8_t[width*height*3]{}) {}

    bool Bitmap::write(std::string filename) {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        // Calculate the size of the file
        fileHeader.fileSize = sizeof(BitmapFileHeader)
                + sizeof(BitmapInfoHeader)
                + width * height * 3;

        // Set the data offset
        fileHeader.dataOffset = sizeof(BitmapFileHeader)
                + sizeof(BitmapInfoHeader);

        infoHeader.width = width;
        infoHeader.height = height;

        return false;
    }

    void Bitmap::setPixel(int x, int y,
            uint8_t red, uint8_t green, uint8_t blue) {

    }

}
