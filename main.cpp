#include "header.h"

int main()
{
    //funkcja hashujaca metoda lancuchowa
    cout<<"Funkcja hashujaca metoda lancuchowa"<<endl;
    MetodaLancuchowa ml;
    //ml.test();
    cout<<endl;
    //algorytm naiwny
    cout<<"Algorytm naiwny"<<endl;
    Naiwny naiwny;
    naiwny.test();
    cout<<endl;
    //algorytm Rabina Karpa
    cout<<"Algorytm Rabina-Karpa"<<endl;
    RabinKarpINT rkI;
    //rkI.test();
    RabinKarpCHAR rkC;
    rkC.test();
    cout<<endl;
    //automat skonczony
    AutomatSkonczony as;

    //algorytm KMP
    cout<<"Algorytm KMP"<<endl;
    KMP kmp;
    kmp.test();
    return 0;
}