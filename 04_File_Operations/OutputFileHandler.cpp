#include "OutputFileHandler.h"

OutputFileHandler::OutputFileHandler(const std::string &filename)
        : filename(filename) {
    stream.open(filename, std::ios::app);
}

OutputFileHandler::~OutputFileHandler() {
    if (is_open()) {
        stream.close();
        std::cout << "File " << filename << " has been closed.\n";
    }
}

void operator<<(OutputFileHandler& of, const std::string& s) {
    of.stream << s;
}