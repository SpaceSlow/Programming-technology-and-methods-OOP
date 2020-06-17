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
    virtual bool readFilmsFromFile(string filename);
    virtual bool writeFilmsToFile(string filename);
    virtual void multiMethod(ofstream *fout);
};

#endif //FILMLIST_H
