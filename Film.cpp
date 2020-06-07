//
// Created by garry on 27.02.2020.
//

#include <fstream>

#include "Film.h"

using std::string;
using std::endl;


string Film::getTypeFilm() {
    return "Film";
}

void Film::readFromFile(ifstream *fin) {
    getline(*fin, this->country);       // Страна, в которой выпустили фильм фильма
    getline(*fin, this->title);        // Название фильма
}

void Film::writeToFile(ofstream *fout) {
    *fout << endl; // Пустая строка для читабельности
    *fout << "Type film: " << this->getTypeFilm() << endl;
    *fout << "Country: " << this->country << endl;
    *fout << "Title: " << this->getTitle() << endl;
}

string Film::getTitle() {
    return this->title;
}

int Film::getVowelsNumberInTitle() {
    string vowels = "aeiou";
    int vowelsCount = 0;
    for (int i = 0; i < this->title.length(); ++i) {
        if (vowels.find(this->title[i]) != -1) {
            vowelsCount++;
        }
    }
    return vowelsCount;
}

string FictionFilm::getTypeFilm() {
    return "Fiction";
}

void FictionFilm::readFromFile(ifstream *fin) {
    Film::readFromFile(fin);
    getline(*fin, this->stageDirector);
}

void FictionFilm::writeToFile(ofstream *fout) {
    Film::writeToFile(fout);
    *fout << "Directed by " << this->stageDirector << endl;
}

string CartoonFilm::getTypeCartoon() {
    switch (this->cartoon) {
        case HAND_DRAWN:
            return "Hand drawn";
        case CLAY:
            return "Clay";
        case COMPUTER:
            return "Computer";
        case DOLL:
            return "Doll";
        default:
            return "";
    }
}

void CartoonFilm::setTypeCartoon(string typeCartoon) {
    enum typeCartoon cartoon;
    if (typeCartoon == "Hand drawn")
        cartoon = HAND_DRAWN;
    else if (typeCartoon == "Clay")
        cartoon = CLAY;
    else if (typeCartoon == "Computer")
        cartoon = COMPUTER;
    else if (typeCartoon == "Doll")
        cartoon = DOLL;
    this->cartoon = cartoon;
}

string CartoonFilm::getTypeFilm() {
    return "Cartoon";
}

void CartoonFilm::readFromFile(ifstream *fin) {
    Film::readFromFile(fin);
    string typeCartoon;
    getline(*fin, typeCartoon);
    this->setTypeCartoon(typeCartoon);
}

void CartoonFilm::writeToFile(ofstream *fout) {
    Film::writeToFile(fout);
    *fout << "Type animation: " << this->getTypeCartoon() << endl;
}

string DocumentaryFilm::getTypeFilm() {
    return "Documentary";
}

void DocumentaryFilm::readFromFile(ifstream *fin) {
    Film::readFromFile(fin);
    string year;
    getline(*fin, year);
    this->yearOfRelease = stoi(year);
}

void DocumentaryFilm::writeToFile(ofstream *fout) {
    Film::writeToFile(fout);
    *fout << "Year of release: " << this->yearOfRelease << endl;
}
