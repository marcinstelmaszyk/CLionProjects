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

    private:
        std::pair<int, int> getFractalSize() const;
        void calculateIteration();
        void drawFractal();
        void writeBitmap(const std::string& name);
        void addZoom(const Zoom& zoom);
    public:
        FractalCreator(int width, int height);

        void addZoom(int x, int y, double scale);
        void run(const std::string& filename);
    };

}

