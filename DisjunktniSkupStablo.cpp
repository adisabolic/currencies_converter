#include "DisjunktniSkupStablo.h"
#include <iostream>
using namespace std;

/* Dodaje novi odnos dvije valute. Provjerava da li mozda ni jedna valuta ne postoji dosad u stablima, da li samo jedna ili ako obje postoje
   u slucaju da su u razlicitim stablima vrsi uniju ta dva stabla tako sto zalijepi stablo manje visine na drugo. U slucaju da su valute u istom stablu
   ne radi nista.
*/

void DisjunktniSkupStablo::Dodaj(string v1, string v2, double odnos) {

    double d1(1), d2(1);
    pair<string, double> s1(Nadji(v1, d1)), s2(Nadji(v2, d2));
    if(s1.first == "" && s2.first == "") { // Novo stablo
        visine[v1] = visine[v2] = 0;
        roditelji[v1] = {v2, odnos};
        roditelji[v2] = {v2, 1};
        cout<<"Prvo pojavljivanje obje valute."<<endl;
    }
    else if(s1.first != s2.first)  { // Unija
        if(s1.first == "" || s2.first == "") {
            if(s2.first == "") {
                roditelji[v2].first = s1.first;
                roditelji[v2].second = (1/odnos) * d1;
                visine[v2] = visine[s1.first];
                cout<<"Prvo pojavljivanje valute "<<v2<<"."<<endl;
            }
            else{
                roditelji[v1].first = s2.first;
                roditelji[v1].second = odnos * d2;
                visine[s1.first] = visine[s2.first];
                cout<<"Prvo pojavljivanje valute "<<v1<<"."<<endl;
            }
        }
        else {
            if(visine[s1.first] < visine[s2.first]) {
                roditelji[s1.first].first = s2.first;
                roditelji[s1.first].second = odnos * d2;
                cout<<"Stablo valute "<<v1<<" kacim na stablo valute "<<v2<<"."<<endl;
            }
            else {
                roditelji[s2.first].first = s1.first;
                roditelji[s2.first].second = (1/odnos) * d1;
                cout<<"Stablo valute "<<v2<<" kacim na stablo valute "<<v1<<"."<<endl;
            }
            if(visine[s1.first] == visine[s2.first])
                visine[s1.first]++;
        }
    }
    else {
        cout<<"Valute su vec u istom stablu."<<endl;
    }
}

/* Vraca koliko 1 novcana jedinica valute v1 iznosi u valuti v2.
*/

double DisjunktniSkupStablo::VratiOdnos(string v1, string v2) {

    double d1(1), d2(1);
    pair<string, double> s1(Nadji(v1, d1)), s2(Nadji(v2, d2));
    if(s1.first != s2.first)
        return -1;
    else
        return (d1/d2);
}

/* Pronalazi rekurzivno korijen stabla valute v, usput stavljajuci sve valute na putu kao djecu korijena. Usput se racuna i odnos
   valute v i valute u korijenu stabla.
*/

pair<string, double> DisjunktniSkupStablo::Nadji(string v, double &d) {

    if(roditelji.find(v) == roditelji.end())
        return {"", -1};

    if(v != roditelji[v].first) {
        d *= roditelji[v].second;
        roditelji[v].first = Nadji(roditelji[v].first, d).first;
        roditelji[v].second = d;
    }
    return {roditelji[v].first, d};
}

/* Nadje valutu kojoj se mijenja vrijednost u heš tabeli i sve valute kojoj je ta valuta roditelj te ih updateuje na odgovarajuci nacin.
   Varijabla procenat moze biti ili pozitivna (porast vrijednosti) ili negativna (pad vrijednosti).
*/

void DisjunktniSkupStablo::PromjenaProcenat(string v, double procenat) {

    if(roditelji.find(v) == roditelji.end())
        cout<<"Ne postoji valuta u sistemu."<<endl;
    else {
        if(roditelji[v].first != v)
            roditelji[v].second *= (1 + procenat/100);
        for (auto it = roditelji.begin(); it != roditelji.end(); it++)
            if(it->second.first == v && it->first != v)
                it->second.second *= (1 - procenat/100);
    }
    if(procenat > 0)
        cout<<"Valuta "<<v<<" je povecala svoju vrijednost za "<<procenat<<"%."<<endl;
    else
        cout<<"Valuta "<<v<<" je smanjila svoju vrijednost za "<<-procenat<<"%."<<endl;
}

bool DisjunktniSkupStablo::imaLi(string v) {

    return roditelji.find(v) != roditelji.end();
}


