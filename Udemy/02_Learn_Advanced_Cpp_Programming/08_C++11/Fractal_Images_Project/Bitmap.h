#pragma once

#include <string>
#include <memory>

namespace btmap {

    class Bitmap {
    private:
        int width{0};
        int height{0};
        std::unique_ptr<uint8_t[]> pPixels{nullptr};

    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(std::string filename);
        std::pair<int, int> dimensions() const;
    };

}