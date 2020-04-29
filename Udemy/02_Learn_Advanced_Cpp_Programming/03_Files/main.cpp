#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "Person.h"

using namespace std;

void parseInput() {
    ifstream inFile("input_text.txt");
    if (inFile.is_open()) {
        while(inFile) {
            string line;
            getline(inFile, line, ':');

            int population;
            inFile >> population;
            inFile >> ws;
            cout << line << " -- " << population << endl;
        }
        inFile.close();
    }
}

void writeBinaryFile(const std::string& fileName) {
    ofstream outputFile;
    outputFile.open(fileName, ios::binary);

    Person someone {"Frodo", 220, 0.8};

    if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<const char *>(&someone), sizeof(Person));

        outputFile.close();
    } else {
        cout << "Could not create file " + fileName;
    }
}

void readBinaryFile(const std::string& fileName) {
    ifstream outputFile;
    outputFile.open(fileName, ios::binary);

    Person someone {};

    if (outputFile.is_open()) {
        outputFile.read(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();
    } else {
        cout << "Could not create file " + fileName;
    }
    cout << "Name: " << someone.name << endl;
}




int main() {
    std::ofstream outFile;
    std::string outputFile = "text.txt";

    //outFile.open(outputFile);
    //if (outFile.is_open()) {
    //    outFile << "Hello there" << endl;
    //    outFile.close();
    //}
    //
    //ifstream inFile("input_text.txt");
    //if (inFile.is_open()) {
    //    string line;
    //    inFile >> line;
    //    getline(inFile, line);
    //    cout << line;
    //
    //    inFile.close();
    //}

    //stringstream ss;
    //ss << "This is the second to last.\nAnd this one is last.";
    //string s;
    //getline(ss, s);
    //cout << s << flush;
    //std::this_thread::sleep_for(std::chrono::seconds(2));
    //getline(ss, s);
    //cout << '\r' << s << endl;
    //std::this_thread::sleep_for(std::chrono::seconds(5));

    // Parsing input
    //parseInput();

    // Binary
    writeBinaryFile("test.bin");
    readBinaryFile("test.bin");
    return 0;
}
