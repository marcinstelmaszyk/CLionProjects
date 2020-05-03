#include "FractalCreator.h"

using namespace btmap;

int main() {
    FractalCreator fractal{800, 600};

    fractal.addRange(0.3, RGB(255, 0, 0));
    fractal.addRange(0.5, RGB(255, 255, 0));
    fractal.addRange(1.0, RGB(255, 255, 255));

    fractal.addZoom(295, 202, 0.1);
    fractal.addZoom(312, 304, 0.1);
    fractal.run("Mandelbrot_Fractal.bmp");

    return 0;
}
