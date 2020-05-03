#include <cmath>

#include "FractalCreator.h"
#include "Mandelbrot.h"
#include "RGB.h"

namespace btmap {

    FractalCreator::FractalCreator(int width, int height)
        : bitmap(width, height), zoomList(width, height),
          histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{0}),
          fractal(new int[width*height]{0}) {
        addZoom(width / 2, height / 2, 4.0 / width);
    }

    void FractalCreator::addZoom(const Zoom &zoom) {
        zoomList.add(zoom);
    }

    void FractalCreator::addZoom(int x, int y, double scale) {
        addZoom(Zoom(x, y, scale));
    }

    void FractalCreator::writeBitmap(const std::string& name) {
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

    void FractalCreator::drawFractal() {
        auto dim = getFractalSize();

        RGB startColor{0, 0, 0};
        RGB endColor{0, 0, 255};
        RGB colorDiff = endColor - startColor;

        for (int y = 0; y < dim.second; y++) {
            for (int x = 0; x < dim.first; x++) {

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                int iterations = fractal[y * dim.first + x];

                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    double hue = 0.0;
                    for (int i = 0; i <= iterations; ++i) {
                        hue += ((double) histogram[i]) / totalIterations;
                    }

                    red = startColor.r + colorDiff.r * hue;
                    green = startColor.g + colorDiff.g * hue;
                    blue = startColor.b + colorDiff.b * hue;
                }

                bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    std::pair<int, int> FractalCreator::getFractalSize() const {
        auto dimensions = bitmap.dimensions();
        return {dimensions.first, dimensions.second};
    }

    void FractalCreator::run(const std::string &filename) {
        calculateIteration();
        drawFractal();
        writeBitmap(filename);
    }

    void FractalCreator::addRange(int rangeEnd, const RGB &rgb) {
        ranges.emplace_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        colors.emplace_back(rgb);
    }

}

