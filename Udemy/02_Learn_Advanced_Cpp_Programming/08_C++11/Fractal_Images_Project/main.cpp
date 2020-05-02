#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace btmap;

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT/3; y++) {
        for (int x = 0; x < WIDTH/2; x++)
            bitmap.setPixel(x, y, 0, 255, 0);
    }

    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
