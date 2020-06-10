#ifndef VALUTE_H
#define VALUTE_H
#include <vector>
#include <string>
#include "DisjunktniSkupStablo.h"
using namespace std;


class Valute {

    DisjunktniSkupStablo stablo;

public:
    Valute(string);
    double nadji(string, string);
    void dodaj(string, string, double);

    void promjenaValute(string, double);
    bool imaLiValute(string);

};


#endif // VALUTE_H

