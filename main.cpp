#include <iostream>
#include "Valute.h"
using namespace std;

int main() {

    Valute v("valute.txt");
    cout<<"---------------------"<<endl;
    cout<<"EUR - IND - "<<v.nadji("EUR", "IND")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"AUD - CAD - "<<v.nadji("AUD", "CAD")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"SGD - IND - "<<v.nadji("SGD", "IND")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"HRK - YEN - "<<v.nadji("HRK", "YEN")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"YUAN - TUR - "<<v.nadji("YUAN", "TUR")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"TUR - EUR - "<<v.nadji("TUR", "EUR")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"CAD - HRK - "<<v.nadji("CAD", "HRK")<<endl;

    cout<<endl<<"Smanjujem vrijednost EUR za 10%"<<endl;
    v.promjenaValute("EUR", -10);

    cout<<"---------------------"<<endl;
    cout<<"EUR - IND - "<<v.nadji("EUR", "IND")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"AUD - CAD - "<<v.nadji("AUD", "CAD")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"EUR - YEN - "<<v.nadji("EUR", "YEN")<<endl;

    cout<<"---------------------"<<endl;
    cout<<"CAD - EUR - "<<v.nadji("CAD", "EUR")<<endl;
}
