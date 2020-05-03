#include <fstream>
#include <iostream>

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

        std::ofstream file;
        file.open(filename, std::ios::out | std::ios::binary);

        if (!file) {
            return false;
        }

        file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
        file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
        file.write(reinterpret_cast<char*>(pPixels.get()), 3*height*width);

        file.close();
        return true;
    }

    void Bitmap::setPixel(int x, int y,
            uint8_t red, uint8_t green, uint8_t blue) {

        // Set pointer to pixel's memory location
        uint8_t *pPixel = pPixels.get();
        pPixel += (3 * y * width) + 3 * x;

        // Little endian used here
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }

    std::pair<int, int> Bitmap::dimensions() const {
        return {width, height};
    }

}
