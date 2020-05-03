#include <complex>
#include "Mandelbrot.h"

namespace btmap {

    Mandelbrot::Mandelbrot() {}

    int btmap::Mandelbrot::getIterations(double x, double y) {
        std::complex<double> z = 0;
        std::complex<double> c(x, y);

        int iterations = 0;

        while (iterations < MAX_ITERATIONS) {
            z = z*z + c;

            if (std::norm(z) > 2)
                break;

            ++iterations;
        }

        return iterations;
    }

}