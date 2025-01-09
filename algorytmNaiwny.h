#pragma once
#include "header.h"
using namespace std;

class Naiwny{
public:
    void naiwny(char* text, int n, char* wzorzec, int m)
    {
        bool znaleziono = false;
        for (int s = 0, end = n - m + 1; s < end; s++)
        {
            int i;
            for (i = 0; i < m && text[s + i] == wzorzec[i]; ++i)
            {
                //porównywanie znaków
            }
            if (i == m)
            {
                cout<<"Pozycja: "<<s<<endl;;
                znaleziono = true;
            }
        }
        if(znaleziono == false)
        {
            cout<<"Nie znaleziono wzorca"<<endl;
        }
    }
    void test()
    {
        char textC[] = "bacbababaaababababcababccaababababca";
        char tabC[] = "ababababca";
        int n = strlen(textC);
        int m = strlen(tabC);
        naiwny(textC, n, tabC, m);
    }
};



