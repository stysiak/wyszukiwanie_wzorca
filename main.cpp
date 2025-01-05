#include "header.h"

int main()
{
    //funkcja hashujaca metoda lancuchowa
    MetodaLancuchowa ml;
    //ml.test();
    //algorytm naiwny
    Naiwny naiwny;
    //naiwny.test();
    //algorytm Rabina Karpa
    RabinKarp rk;
    //rk.test();
    //automat skonczony
    AutomatSkonczony as;

    //algorytm KMP
    KMP kmp;
    kmp.test();
    return 0;
}