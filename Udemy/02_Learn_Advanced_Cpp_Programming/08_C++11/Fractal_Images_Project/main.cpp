#include "FractalCreator.h"

using namespace btmap;

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    FractalCreator fractal{WIDTH, HEIGHT};

    fractal.addZoom(295, HEIGHT - 202, 0.1);
    fractal.addZoom(312, HEIGHT - 304, 0.1);

    fractal.calculateIteration();
    fractal.drawFractal();
    fractal.writeBitmap("Mandelbrot_Fractal.bmp");

    return 0;
}
