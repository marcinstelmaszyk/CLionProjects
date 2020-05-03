#pragma once
#include "Zoom.h"

#include <vector>
#include <utility>

namespace btmap {

    class ZoomList {
    private:
        double xCenter{0};
        double yCenter{0};
        double scale{1.0};

        int width{0};
        int height{0};
        std::vector<Zoom> zooms;
    public:
        ZoomList(int w, int h);
        void add(const Zoom& zoom);
        std::pair<double, double> doZoom(int x, int y) const;
    };

}
