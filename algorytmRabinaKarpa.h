#pragma once
#include "header.h"
using namespace std;
class RabinKarp{
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
        int base = 1;

        // Wyliczamy największą potęgę podstawy (dla przesunięcia hasha)
        for (int i = 1; i < m; i++)
        {
            base = (base * 10) % 13;
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
