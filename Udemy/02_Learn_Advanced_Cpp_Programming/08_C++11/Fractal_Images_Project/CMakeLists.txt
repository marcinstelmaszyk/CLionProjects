cmake_minimum_required(VERSION 3.16)
project(Fractal_Images_Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(Fractal_Images_Project main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h Zoom.cpp Zoom.h ZoomList.cpp ZoomList.h FractalCreator.cpp FractalCreator.h)