#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace btmap;

int main() {
    Bitmap bitmap(800, 600);
    bitmap.write("test.bmp");

    std::cout << "Finished." << std::endl;
    return 0;
}
