#include <iostream>

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

    mandelbrotFractal.addZoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH);
    mandelbrotFractal.addZoom(295, HEIGHT - 202, 0.1);
    mandelbrotFractal.addZoom(312, HEIGHT - 304, 0.1);

    mandelbrotFractal.calculateIteration();
    mandelbrotFractal.drawFractal();
    mandelbrotFractal.writeBitmap("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
