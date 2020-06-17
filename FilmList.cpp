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

void FilmList::readFilmsFromFile(string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        throw "The input file was not opened. Check the file path and file permissions.";
    }

    bool doSort = false;
    int numFilms;
    string tmp, typeFilm, sortFilms, filterFilms;
    getline(fin, tmp);          // Количество фильмов

    try {
        numFilms = stoi(tmp);
        if (std::to_string(numFilms) != tmp) {
            throw std::invalid_argument("invalid argument");
        }
    } catch (const std::invalid_argument &msg) {
        throw "The input file contains an invalid value for the number of films. Allowed type number of films is integer.";
    } catch (const std::out_of_range &msg) {
        throw "The input file contains a very large number of films.";
    }

    getline(fin, sortFilms);       // Сортировка

    if (sortFilms == "Sort") {
        doSort = true;
    } else if (sortFilms != "No sort") {
        throw "The input file contains an invalid sorting value. See README.";
    }

    getline(fin, filterFilms); // Фильтр


    for (int i = 0; i < numFilms; ++i) {
        getline(fin, tmp);          // Пропуск пустой строки
        getline(fin, typeFilm);    // Тип фильма
        Film *film;
        if (typeFilm == "Fiction") {
            film = new FictionFilm();
        } else if (typeFilm == "Cartoon") {
            film = new CartoonFilm();
        } else if (typeFilm == "Documentary") {
            film = new DocumentaryFilm();
        } else {
            fin.close();
            throw "The input file contains an incorrect film type. See README.";
        }
        film->readFromFile(&fin);

        if (filterFilms == "All" or filterFilms == film->getTypeFilm()) {
            this->addFilm(film);
        }
    }

    if (doSort) {
        this->sortFilmsByVowelsNumber();
    }

    fin.close();
}

void FilmList::writeFilmsToFile(string filename) {

    ofstream fout(filename);

    fout << "Number of films: " << this->size << endl; // Ввод размера списка в файл

    if (!this->size) {
        fout.close();
        return;
    }

    FilmItem *currentFilmItem = this->firstFilm; // инициализация текущего элемента списка

    for (int i = 0; i < this->size; ++i) {
        currentFilmItem->film->writeToFile(&fout);
        currentFilmItem = currentFilmItem->nextFilm;
    }

    fout.close();
}

void FilmList::sortFilmsByVowelsNumber() {
    for(FilmItem* filmItem2 = this->firstFilm; filmItem2; filmItem2 = filmItem2->nextFilm)
    {
        for(FilmItem* filmItem1 = this->firstFilm; filmItem1->nextFilm; filmItem1 = filmItem1->nextFilm)
        {
            if(filmItem1->film->getVowelsNumberInTitle() > filmItem1->nextFilm->film->getVowelsNumberInTitle())
            {
                std::iter_swap(&filmItem1->film, &filmItem1->nextFilm->film);
            }
        }
    }
}

int FilmList::getSize() {
    return this->size;
}

FilmItem * FilmList::getFirstFilm() {
    return this->firstFilm;
}

FilmItem *FilmList::getLastFilm() {
    return this->lastFilm;
}
