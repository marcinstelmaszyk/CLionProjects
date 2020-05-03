#include <cmath>
#include <iostream>

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

        for (int y = 0; y < dim.second; y++) {
            for (int x = 0; x < dim.first; x++) {
                int iterations = fractal[y * dim.first + x];

                int range = getRange(iterations);
                int rangeTotal = rangeTotals[range];
                int rangeStart = ranges[range];

                RGB& startColor = colors[range];
                RGB& endColor = colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if (iterations != Mandelbrot::MAX_ITERATIONS) {
                    int totalPixels = 0;
                    for (int i = rangeStart; i <= iterations; ++i) {
                        totalPixels += histogram[i];
                    }

                    red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
                    green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
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
        calculateRangeTotals();
        drawFractal();
        writeBitmap(filename);
    }

    void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
        ranges.emplace_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        colors.emplace_back(rgb);

        if (gotFirstRange)
            rangeTotals.push_back(0);

        gotFirstRange = true;
    }

    void FractalCreator::calculateRangeTotals() {
        int rangeIndex = 0;

        for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
            int pixels = histogram[i];

            if (i >= ranges[rangeIndex + 1])
                rangeIndex++;

            rangeTotals[rangeIndex] += pixels;
        }
        for (int value : rangeTotals)
            std::cout << "Range total: " << value << std::endl;
    }

    int FractalCreator::getRange(int iterations) const {
        int range = 0;

        for (int i = 1; i < ranges.size(); ++i) {
            range = i;

            if (ranges[i] > iterations)
                break;
        }

        range--;

        return range;
    }

}

