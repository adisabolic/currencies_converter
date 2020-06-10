#ifndef DISJUNKTNI_SKUP_STABLO_H
#define DISJUNKTNI_SKUP_STABLO_H
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Svaki skup je jedno stablo spajanje se vrsi tako sto se stablo manje visine zalijepi na korijen drugog stabla. Za trazenje
kojem stablu neki element pripada cuva se heš tabela roditelji koji za svaki element cuva njegovog roditelja u stablu. Pored toga cuva se i
odnos te valute u odnosu na roditelja (tj. koliko jedna novcana jedinica te valute iznosi u valuti roditelja). Ove dvije vrijednosti se cuvaju kao par.
Kljuc u heš tabeli je string koji odgovara imenu valute.
Potraga ide kroz roditelje dok se ne dodje do korijena stabla te se on i vraca. Cuva se i heš tabela visine kako bi se znalo
koje stablo je manje.
*/

class DisjunktniSkupStablo {

    unordered_map<string, pair<string, double>> roditelji;
    unordered_map<string, int> visine;

public:

    void Dodaj(string, string, double);
    double VratiOdnos(string, string);
    pair<string, double> Nadji(string, double&);

    void PromjenaProcenat(string, double);
    bool imaLi(string);
};

#endif // DISJUNKTNI_SKUP_STABLO_H

