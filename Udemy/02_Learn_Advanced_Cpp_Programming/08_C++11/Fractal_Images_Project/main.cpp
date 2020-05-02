#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace btmap;

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++){
            double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
            double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            uint8_t red = (uint8_t)(256 * static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS);

            bitmap.setPixel(x, y, red, red,red);
            if(red < min) min = red;
            if(red > max) max = red;
        }
    }

    std::cout << min << ", " << max << std::endl;

    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
