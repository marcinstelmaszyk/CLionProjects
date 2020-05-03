#include "FractalCreator.h"

using namespace btmap;

int main() {
    FractalCreator fractal{800, 600};
    fractal.run("Mandelbrot_Fractal.bmp");

    return 0;
}
