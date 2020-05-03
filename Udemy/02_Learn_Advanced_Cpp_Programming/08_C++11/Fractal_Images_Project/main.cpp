#include "FractalCreator.h"

using namespace btmap;

int main() {
    FractalCreator fractal{800, 600};
    fractal.addZoom(295, 202, 0.1);
    fractal.addZoom(312, 304, 0.1);
    fractal.run("Mandelbrot_Fractal.bmp");

    return 0;
}
