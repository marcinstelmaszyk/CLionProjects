#pragma once

#include <string>
#include "Zoom.h"
#include "Bitmap.h"

namespace btmap {

    class FractalCreator {
    public:
        Bitmap bitmap;
    public:
        FractalCreator(int width, int height);

        void calculateIteration();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void writeBitmap(std::string name);
    };

}

