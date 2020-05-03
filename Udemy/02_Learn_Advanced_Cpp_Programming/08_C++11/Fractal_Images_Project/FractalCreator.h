#pragma once

#include <string>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"

namespace btmap {

    class FractalCreator {
    public:
        Bitmap bitmap;
        ZoomList zoomList;
        std::unique_ptr<int[]> histogram;
        std::unique_ptr<int[]> fractal;

    public:
        FractalCreator(int width, int height);

        void calculateIteration();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void writeBitmap(std::string name);
    };

}

