#pragma once

#include <iostream>
#include <fstream>

class OutputFileHandler {
    std::string filename;
    std::ofstream stream;

public:
    OutputFileHandler(const std::string &filename);
    ~OutputFileHandler();

    int is_open() { return stream.is_open(); }

    friend void operator<<(OutputFileHandler& of, const std::string& s);
};