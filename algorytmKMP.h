#pragma once
#include "header.h"
using namespace std;

class KMP{
    public:
    int* tabS(char* wzor, int m)
    {
        int* S = new int[m]; //tablica prefiksow
        S[0] = 0; //pierwszy element zawsze 0
        int k = 0; //dlugosc aktualnego prefiksu
        for (int i = 1; i < m; i++)
        {
            while (wzor[k] != wzor[i] && k > 0)
            {
                k = S[k-1]; //cofanie sie do poprzedniego prefiksu
            }
            if (wzor[i] == wzor[k])
            {
                k++; //zwiekszenie dlugosci dopasowania
            }
            S[i] = k; //zapisanie aktualnego wyniku dlugosci dopasowania prefiksu
            //cout<<wzor[i]<<", " << k << endl;
        }
        return S;
    }

    void KMPfun(char* text, int n, char* wzor, int m)
    {
        int* tabP = tabS(wzor, m); //tablica prefiksow
        int k = 0; //ilosc dopasowanych znakow
        bool znaleziono = false;
        for(int i=0; i<n;i++)
        {
            while(k>0 && wzor[k]!=text[i])
            {
                k=tabP[k-1]; //cofanie się do poprzedniego dopasowania
            }
            if(wzor[k]==text[i])
            {
                k++; //zwieksz ilosc dopasowanych znakow
            }
            if(k==m)
            {
                cout<<"Pozycja: "<<(i-m+1)<<endl; //pozycja gdzie znaleziono dopasowanie
                znaleziono = true;
                k=tabP[k-1]; //szukanie kolejnego dopasowania (trzeba przerobic)
            }
        }
        if(znaleziono == false)
        {
            cout<<"Nie znaleziono wzorca"<<endl;
        }
        delete [] tabP;
    }

    void test()
    {
        char p[] = "ababababca";
        char text[] = "bacbababaaababababcababccaababababca";
        int m = strlen(p);
        //tabS(p, m);
        int n = strlen(text);
        KMPfun(text, n, p, m);
    }
};
