#include "FractalCreator.h"
#include "Mandelbrot.h"

namespace btmap {

    FractalCreator::FractalCreator(int width, int height)
        : bitmap(width, height), zoomList(width, height),
          histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0}),
          fractal(new int[width*height]{0}) {
    }

    void FractalCreator::addZoom(const Zoom &zoom) {
        zoomList.add(zoom);
    }

    void FractalCreator::writeBitmap(std::string name) {
        bitmap.write(name);
    }

    void FractalCreator::calculateIteration() {

    }

}

