//
// Created by garry on 12.06.2020.
//

#ifndef FILM_UNITTESTS_H
#define FILM_UNITTESTS_H

#include "FilmList.h"
#include <cassert>


class UnitTests {
public:
    void run();
private:
    void testSizeAfterAddFilm();
    void testLinksInFilmList();
    void testReadWriteFromFile();
    void testVowelsNumberInFilmTitle();
    void testSortFilmList();
    void testFilterFilmList();
};


#endif //FILM_UNITTESTS_H
