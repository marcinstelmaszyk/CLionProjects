#include <iostream>
#include "ZoomList.h"

namespace btmap {

    ZoomList::ZoomList(int w, int h) : width(w), height(h) {
    }

    void ZoomList::add(const btmap::Zoom &zoom) {
        zooms.emplace_back(zoom);

        xCenter += (zoom.x - width/2) * scale;
        yCenter += (zoom.y - height/2) * scale;

        scale *= zoom.scale;

        std::cout << xCenter << ", " << yCenter << ", " << scale << std::endl;
    }

    std::pair<double, double> ZoomList::doZoom(int x, int y) {
        return std::pair<double, double>(0, 0);
    }


}
