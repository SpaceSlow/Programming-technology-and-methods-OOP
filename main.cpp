#include <iostream>

#include "FilmList.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Type input and output files." << endl;
        return -1;
    }

    FilmList *filmList = new FilmList();

    string inputPath = argv[1];
    bool isSuccessRead = filmList->readFilmsFromFile(inputPath);
    if (!isSuccessRead) {
        cout << "Failed to open file for reading." << endl;
        return -1;
    }

    string outputPath = argv[2];
    bool isSuccessWrite = filmList->writeFilmsToFile(outputPath);
    if (!isSuccessWrite) {
        cout << "Failed to open file for writing." << endl;
        return -1;
    }

    cout << "Success." << endl;
    return 0;
}
