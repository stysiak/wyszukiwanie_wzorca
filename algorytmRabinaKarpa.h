#pragma once
#include "header.h"
using namespace std;
class RabinKarpINT{
    public:
    int fHash(int* p, int m)
    {
        int h = 0;
        for (int i = 0; i < m; i++)
        {
            h = (10 * h + p[i]) % 13;
        }
        return h;
    }

    int Rabin_Karp(int* text, int n, int* wzorzec, int m)
    {
        int p = fHash(wzorzec, m);
        int t = fHash(text, m);
        int base = 1; //bo 10^0=1

        // Wyliczamy największą potęgę podstawy (dla przesunięcia hasha)
        for (int i = 1; i < m; i++)
        {
            base = (base * 10) % 13; //base=10^(m-1)%13
        }

        for (int s = 0, end = n - m + 1, i; s < end; s++)
        {
            if (p == t)
            {
                for (i = 0; i < m && text[s + i] == wzorzec[i]; ++i)
                {
                
                }
                if (i == m)
                {
                    return s;
                }
            }
            if ((s + m) < n)
            {
                t = (10 * (t - text[s] * base) + text[s + m]) % 13;
                if (t < 0)
                {
                    t += 13;
                }
            }
        }

        return -1;
    }

    void test()
    {
        int tab[] = { 3,1,4,1,5 };
        int text[] = { 2,3,5,9,0,2,3,1,4,1,5,2,6,7,3,9,9 };
        cout << Rabin_Karp(text, 17, tab, 5) << endl;
    }
};

class RabinKarpCHAR{
    public:
    int fHash(char* p, int m, int q) 
    {
        int h = 0;
        for (int i = 0; i < m; i++)
        {
            h = (10 * h + p[i]) % q; //obliczanue hasha na podstawie kodu ASCII
        }
        return h;
    }

    void Rabin_Karp(char* text, int n, char* wzorzec, int m, int d, int q)
    {
        int p = fHash(wzorzec, m, q);
        int t = fHash(text, m, q); //obliczanie hasha dla okna tekstu o długosci wzorca
        int base = 1; //base=d^0

        //wyliczamy największą potęgę podstawy (dla przesunięcia hasha)
        for (int i = 1; i < m; i++)
        {
            base = (base * d) % q; //base=d^(m-1)%13
        }
        //cout<<base<<endl;

        bool znaleziono = false;
        //przesuwanie okna w tekscie
        for (int s = 0, end = n - m + 1, i; s < end; s++)
        {
            if (p == t) //jesli hashe się zgadzają, to sprawdzamy czy ciąg jest git
            {
                for (i = 0; i < m && text[s + i] == wzorzec[i]; ++i)
                {
                    //porównywanie tych znaków
                }
                if (i == m)
                {
                    cout<<"Pozycja: "<<s<<endl;
                    znaleziono = true;
                }
            }
            if ((s + m) < n) //aktualizacja wartosci hasha dla kolejnego okna jeśli jeszcze sie miesci w tekscie
            {
                t = (d * (t - text[s] * base) + text[s + m]) % q; 
                //10 przesunięcie, t stary hash, text[s] stary znak a *base to jego waga, usunięcie jego wpływu to odjęcie
                //text[s+m] to dodanie nowego znaku z prawej, jego waga to base^0, redukcja modulo
                if (t < 0) //ujemny hash naprawa
                {
                    t += q;
                }
            }
        }
        if(znaleziono == false)
        {
            cout<<"Nie znaleziono wzorca"<<endl;
        }

    }

    void test()
    {
        char p[] = "ababababca";
        char text[] = "bacbababaaababababcababccaababababca";
        int m = strlen(p);
        int n = strlen(text);
        Rabin_Karp(text, n, p, m, 256, 101);
    }
};
