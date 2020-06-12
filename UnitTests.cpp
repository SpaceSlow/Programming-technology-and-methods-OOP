//
// Created by garry on 12.06.2020.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "UnitTests.h"

using std::cout;
using std::endl;
using std::stringstream;


void UnitTests::run() {
    this->testSizeAfterAddFilm();
    this->testLinksInFilmList();
    this->testReadWriteFromFile();
    this->testVowelsNumberInFilmTitle();
    this->testSortFilmList();
    this->testFilterFilmList();
}

void UnitTests::testSizeAfterAddFilm() {
    FilmList *filmList = new FilmList();

    FictionFilm *film = new FictionFilm();

    assert(filmList->getSize() == 0);
    filmList->addFilm(film);
    assert(filmList->getSize() == 1);
    filmList->addFilm(film);
    assert(filmList->getSize() == 2);
    filmList->addFilm(film);
    assert(filmList->getSize() == 3);

    cout << "Success testSizeAfterAddFilm" << endl;
}

void UnitTests::testLinksInFilmList() {
    FilmList *filmList = new FilmList();

    FictionFilm *film1 = new FictionFilm();
    DocumentaryFilm *film2 = new DocumentaryFilm();
    CartoonFilm *film3 = new CartoonFilm();

    filmList->addFilm(film1);
    assert(film1 == filmList->getFirstFilm()->film);
    filmList->addFilm(film2);
    assert(film2 == filmList->getFirstFilm()->nextFilm->film);
    assert(film2 == filmList->getLastFilm()->film);
    filmList->addFilm(film3);
    assert(film3 == filmList->getFirstFilm()->nextFilm->nextFilm->film);
    assert(film3 == filmList->getLastFilm()->film);
    assert(filmList->getLastFilm()->nextFilm == nullptr);

    cout << "Success testLinksInFilmList" << endl;
}

void UnitTests::testReadWriteFromFile() {

    string inputPath = "test_files/testReadWriteFromFile_in.txt";
    string outputPath = "test_files/testReadWriteFromFile_out.txt";

    string expected = "Number of films: 4\n"
                      "\n"
                      "Type film: Fiction\n"
                      "Country: USA\n"
                      "Title: Pulp Fiction\n"
                      "Directed by Quentin Tarantino\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Documentary\n"
                      "Country: USA\n"
                      "Title: The Story of Queen: Mercury Rising\n"
                      "Year of release: 2011\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n";

    FilmList *filmList = new FilmList();

    filmList->readFilmsFromFile(inputPath);
    filmList->writeFilmsToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success testReadWriteFromFile" << endl;
}

void UnitTests::testVowelsNumberInFilmTitle() {
    string inputPath = "test_files/testVowelsNumberInFilmTitle.txt";

    FilmList *filmList = new FilmList();

    filmList->readFilmsFromFile(inputPath);

    assert(filmList->getFirstFilm()->film->getVowelsNumberInTitle() == 4);
    assert(filmList->getFirstFilm()->nextFilm->film->getVowelsNumberInTitle() == 0);
    assert(filmList->getLastFilm()->film->getVowelsNumberInTitle() == 10);

    cout << "Success testVowelsNumberInFilmTitle" << endl;
}

void UnitTests::testSortFilmList() {
    string inputPath = "test_files/testSortFilmList_in.txt";
    string outputPath = "test_files/testSortFilmList_out.txt";


    string expected = "Number of films: 4\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n"
                      "\n"
                      "Type film: Fiction\n"
                      "Country: USA\n"
                      "Title: Pulp Fiction\n"
                      "Directed by Quentin Tarantino\n"
                      "\n"
                      "Type film: Documentary\n"
                      "Country: USA\n"
                      "Title: The Story of Queen: Mercury Rising\n"
                      "Year of release: 2011\n";

    FilmList *filmList = new FilmList();

    filmList->readFilmsFromFile(inputPath);
    filmList->writeFilmsToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success testSortFilmList" << endl;
}

void UnitTests::testFilterFilmList() {
    string inputPath = "test_files/testFilterFilmList_in.txt";
    string outputPath = "test_files/testFilterFilmList_out.txt";


    string expected = "Number of films: 2\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n";

    FilmList *filmList = new FilmList();

    filmList->readFilmsFromFile(inputPath);
    filmList->writeFilmsToFile(outputPath);

    ifstream inFile(outputPath);
    stringstream buffer;
    buffer << inFile.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success testFilterFilmList" << endl;
}
