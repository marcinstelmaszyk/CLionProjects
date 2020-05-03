#pragma once

#include <string>

#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"

namespace btmap {

    class FractalCreator {
        Bitmap bitmap;
        ZoomList zoomList;
        std::unique_ptr<int[]> histogram;
        std::unique_ptr<int[]> fractal;
        int totalIterations{0};
    public:
        FractalCreator(int width, int height);

        void run(const std::string& filename);
        std::pair<int, int> getFractalSize() const;
        void calculateIteration();
        void drawFractal();
        void addZoom(const Zoom& zoom);
        void addZoom(int x, int y, double scale);
        void writeBitmap(const std::string& name);
    };

}

