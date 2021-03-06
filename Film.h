//
// Created by garry on 27.02.2020.
//

#ifndef FILM_H
#define FILM_H

#include <string>

using std::string;
using std::ifstream;
using std::ofstream;


class Film {
private:
    string title;
    string country;
public:
    Film() {};
    string getTitle();
    virtual string getTypeFilm() = 0;
    virtual void readFromFile(ifstream *fin);
    virtual void writeToFile(ofstream *fout);
    virtual int getVowelsNumberInTitle();
    virtual void multiMethod(Film *otherFilm, ofstream *fout);
    virtual void mMFiction(ofstream *fout);
    virtual void mMCartoon(ofstream *fout);
    virtual void mMDocumentary(ofstream *fout);
};

class FictionFilm : public Film {
private:
    string stageDirector;
public:
    FictionFilm() {};
    string getTypeFilm() override;
    void readFromFile(ifstream *fin);
    void writeToFile(ofstream *fout);
    void multiMethod(Film *otherFilm, ofstream *fout);
    void mMFiction(ofstream *fout);
    void mMCartoon(ofstream *fout);
    void mMDocumentary(ofstream *fout);
};

enum typeCartoon {CLAY, HAND_DRAWN, COMPUTER, DOLL};

class CartoonFilm : public Film {
private:
    typeCartoon cartoon;
public:
    CartoonFilm() {};
    virtual string getTypeCartoon();
    void setTypeCartoon(string typeCartoon);
    string getTypeFilm() override;
    void readFromFile(ifstream *fin);
    void writeToFile(ofstream *fout);
    void multiMethod(Film *otherFilm, ofstream *fout);
    void mMFiction(ofstream *fout);
    void mMCartoon(ofstream *fout);
    void mMDocumentary(ofstream *fout);
};

class DocumentaryFilm : public Film {
private:
    int yearOfRelease;
public:
    DocumentaryFilm() {};
    string getTypeFilm() override;
    void readFromFile(ifstream *fin);
    void writeToFile(ofstream *fout);
    void multiMethod(Film *otherFilm, ofstream *fout);
    void mMFiction(ofstream *fout);
    void mMCartoon(ofstream *fout);
    void mMDocumentary(ofstream *fout);
};

#endif //FILM_H
