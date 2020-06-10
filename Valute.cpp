#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "Valute.h"
using namespace std;


Valute::Valute(string fajl) {

    ifstream fin(fajl);
    int n;
    fin>>n;
    string v1, v2;
    double odnos;
    cout<<"--------------------------------------- Dodavanje valuta iz fajla ---------------------------------------"<<endl;
    for(int i = 0 ; i < n ; i++) {
        fin>>v1>>v2;
        fin>>odnos;
        cout<<"---------------------"<<endl;
        stablo.Dodaj(v1, v2, odnos);
        cout<<v1<<" - "<<v2<<" - "<<stablo.VratiOdnos(v1, v2)<<endl;
    }
    cout<<"--------------------------------------- Kraj dodavanja iz fajla ---------------------------------------"<<endl;
    fin.close();
}

double Valute::nadji(string v1, string v2) {

    return stablo.VratiOdnos(v1, v2);
}

void Valute::dodaj(string v1, string v2, double odnos) {

    stablo.Dodaj(v1, v2, odnos);
}

void Valute::promjenaValute(string v, double procenat) {

    stablo.PromjenaProcenat(v, procenat);

}

bool Valute::imaLiValute(string v) {

    return stablo.imaLi(v);
}


