#pragma once

#include <string>

#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

namespace btmap {

    class FractalCreator {
        Bitmap bitmap;
        ZoomList zoomList;
        std::unique_ptr<int[]> histogram;
        std::unique_ptr<int[]> fractal;
        int totalIterations{0};

        std::vector<int> ranges;
        std::vector<RGB> colors;
        std::vector<int> rangeTotals;

        bool gotFirstRange{false};
    private:
        std::pair<int, int> getFractalSize() const;
        void calculateIteration();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(const std::string& name);
        void addZoom(const Zoom& zoom);

    public:
        int getRange(int iterations) const;
    public:
        FractalCreator(int width, int height);

        void addRange(double rangeEnd, const RGB& rgb);
        void addZoom(int x, int y, double scale);
        void run(const std::string& filename);
    };

}

