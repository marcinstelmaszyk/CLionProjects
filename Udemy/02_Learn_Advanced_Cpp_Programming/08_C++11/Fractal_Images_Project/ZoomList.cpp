#include "ZoomList.h"

namespace btmap {

    ZoomList::ZoomList(int w, int h) : width(w), height(h) {
    }

    void ZoomList::add(const btmap::Zoom &zoom) {
        zooms.emplace_back(zoom);

        xCenter += (zoom.x - width/2) * scale;
        yCenter -= (zoom.y - height/2) * scale;
        scale *= zoom.scale;
    }

    std::pair<double, double> ZoomList::doZoom(int x, int y) const {
        double xFractal = (x - width/2) * scale + xCenter;
        double yFractal = (y - height/2) * scale + yCenter;

        return {xFractal, yFractal};
    }


}
