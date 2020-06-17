//
// Created by garry on 30.04.2020.
//

#include <fstream>

#include "FilmList.h"

using std::ifstream;
using std::ofstream;
using std::endl;


FilmList::FilmList() {
    this->size = 0;
    this->firstFilm = nullptr;
    this->lastFilm = nullptr;
}

void FilmList::addFilm(Film *film) {
    FilmItem *newFilmItem = new FilmItem;
    newFilmItem->film = film;
    newFilmItem->nextFilm = nullptr;

    if (this->size == 0) {
        this->firstFilm = newFilmItem;
    } else if (this->size == 1) {
        this->firstFilm->nextFilm = newFilmItem;
        this->lastFilm = newFilmItem;
    } else {
        this->lastFilm->nextFilm = newFilmItem;
        this->lastFilm = newFilmItem;
    }

    this->size++;
}

bool FilmList::readFilmsFromFile(string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        return false;
    }

    int numFilms;
    string tmp, typeFilm;
    getline(fin, tmp);
    numFilms = stoi(tmp);

    for (int i = 0; i < numFilms; ++i) {
        getline(fin, tmp);          // Пропуск пустой строки
        getline(fin, typeFilm);    // Тип фильма
        Film *film;
        if (typeFilm == "Fiction") {
            film = new FictionFilm();
        } else if (typeFilm == "Cartoon") {
            film = new CartoonFilm();
        } else {
            fin.close();
            return false;
        }
        film->readFromFile(&fin);
        this->addFilm(film);
    }
    fin.close();
    return true;
}

bool FilmList::writeFilmsToFile(string filename) {

    ofstream fout(filename);

    fout << "Number of films: " << this->size << endl; // Ввод размера списка в файл

    if (!this->size) {
        fout.close();
        return true;
    }

    FilmItem *currentFilmItem = this->firstFilm; // инициализация текущего элемента списка

    for (int i = 0; i < this->size; ++i) {
        currentFilmItem->film->writeToFile(&fout);
        currentFilmItem = currentFilmItem->nextFilm;
    }

    this->multiMethod(&fout);

    fout.close();
    return true;
}

void FilmList::multiMethod(ofstream *fout) {
    *fout << endl << endl << "Multimethod" << endl;
    if (!this->size) {
        return;
    }

    for(FilmItem *filmItem1 = this->firstFilm; filmItem1->nextFilm; filmItem1 = filmItem1->nextFilm) {
        for(FilmItem *filmItem2 = filmItem1->nextFilm; filmItem2; filmItem2 = filmItem2->nextFilm) {
            filmItem1->film->multiMethod(filmItem2->film, fout);
        }
    }

}