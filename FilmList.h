//
// Created by garry on 30.04.2020.
//

#ifndef FILMLIST_H
#define FILMLIST_H

#include "Film.h"


class FilmItem {
public:
    Film *film;
    FilmItem *nextFilm;
};

class FilmList {
private:
    int size;
    FilmItem *firstFilm;
    FilmItem *lastFilm;
public:
    FilmList();
    virtual void addFilm(Film *film);
    virtual int getSize();
    virtual FilmItem * getFirstFilm();
    virtual FilmItem * getLastFilm();
    virtual bool readFilmsFromFile(string filename);
    virtual bool writeFilmsToFile(string filename);
    virtual void sortFilmsByVowelsNumber();
};

#endif //FILMLIST_H
