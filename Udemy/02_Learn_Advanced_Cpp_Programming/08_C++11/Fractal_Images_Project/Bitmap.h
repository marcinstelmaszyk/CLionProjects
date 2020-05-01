#pragma once
#include <string>

namespace btmap {

    class Bitmap {
    private:
        int width{0};
        int height{0};

    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(std::string filename);
    };

}