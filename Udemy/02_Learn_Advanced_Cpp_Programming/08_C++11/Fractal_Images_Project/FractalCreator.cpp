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
        auto dim = getFractalSize();

        for (int y = 0; y < dim.second; y++) {
            for (int x = 0; x < dim.first; x++){
                auto coords = zoomList.doZoom(x, y);

                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                fractal[y * dim.first + x] = iterations;

                if (iterations != Mandelbrot::MAX_ITERATIONS)
                    histogram[iterations]++;
            }
        }

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
            totalIterations += histogram[i];
        }
    }

    std::pair<int, int> FractalCreator::getFractalSize() const {
        auto dimensions = bitmap.dimensions();
        return {dimensions.first, dimensions.second};
    }

}

