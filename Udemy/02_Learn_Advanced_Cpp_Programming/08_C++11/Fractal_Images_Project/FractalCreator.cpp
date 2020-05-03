#include "FractalCreator.h"

namespace btmap {

    FractalCreator::FractalCreator(int width, int height)
        : bitmap(width, height), zoomList(width, height) {}

    void FractalCreator::addZoom(const Zoom &zoom) {
        zoomList.add(zoom);
    }

}
