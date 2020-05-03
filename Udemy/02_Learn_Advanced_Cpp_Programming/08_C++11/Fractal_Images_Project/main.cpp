#include <iostream>
#include <cmath>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace btmap;

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    FractalCreator mandelbrotFractal{WIDTH, HEIGHT};

    mandelbrotFractal.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    mandelbrotFractal.addZoom(Zoom(295, HEIGHT - 202, 0.1));
    mandelbrotFractal.addZoom(Zoom(312, HEIGHT - 304, 0.1));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++){
            pair<double, double> coords = mandelbrotFractal.zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coords.first, coords.second);

            mandelbrotFractal.fractal[y*WIDTH+x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS)
                mandelbrotFractal.histogram[iterations]++;
        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
        total += mandelbrotFractal.histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = mandelbrotFractal.fractal[y*WIDTH+x];

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0.0;
                for (int i = 0; i <= iterations; ++i) {
                    hue += ((double) mandelbrotFractal.histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            mandelbrotFractal.bitmap.setPixel(x, y, red, green, blue);
        }
    }
    mandelbrotFractal.writeBitmap("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
