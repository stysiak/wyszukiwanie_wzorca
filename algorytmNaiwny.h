#include "header.h"

int naiwny(char* text, int n, char* wzorzec, int m)
{
    for (int s = 0, end = n - m + 1; s < end; s++)
    {
        int i;
        for (i = 0; i < m && text[s + i] == wzorzec[i]; ++i)
        {
            
        }
        if (i == m)
        {
            return s;
        }
    }
    return -1;
}

void test()
{
    char textC[] = "abcabbaabababaabc";
    char tabC[] = "abaabc";
    cout << naiwny(textC, 17, tabC, 5) << endl;
}