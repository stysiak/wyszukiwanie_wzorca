#pragma once
#include "header.h"
using namespace std;

struct lista {
    lista* next;
    string imie;
};

class MetodaLancuchowa{
    public:
    void insertLista(string i, lista* &head)
    {
        lista* nowy = new lista;
        nowy->imie = i;
        nowy->next = nullptr;
        if (head == nullptr)
        {
            head = nowy;
            return;
        }
        lista* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nowy;
    }

    bool szukajLista(string i, lista* head)
    {
        lista* temp = head;
        while (temp)
        {
            if (temp->imie == i)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int funHash(string i)
    {
        int l = i.length();
        int suma = 0;
        for (int j = 0; j < l; j++)
        {
            suma +=i[j];
        }
        suma %= 41;
        return suma;
    }

    bool szukaj(string i, lista* tab[])
    {
        int h = funHash(i);
        for (int j = 0; j < 41; j++)
        {
            if (j == h)
            {
                if (szukajLista(i, tab[j]))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void insert(string i, lista* tab[])
    {
        int h = funHash(i);
        for (int j = 0; j < 41; j++)
        {
            if (j == h)
            {
                insertLista(i, tab[j]);
            }
        }
    }

    void wyswietl(lista* tab[])
    {
        for (int i = 0; i < 41; i++)
        {
            cout << i << ":";
            lista* temp = tab[i];
            while (temp)
            {
                cout << " ---> " << temp->imie;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void test()
    {
        lista* tab[41] = { nullptr };
        insert("Aaron", tab);
        insert("Adam", tab);
        insert("Agnieszka", tab);
        insert("Beata", tab);
        insert("Bartosz", tab);
        insert("Jakub", tab);
        insert("Zbigniew", tab);
        insert("Dariusz", tab);
        insert("Malwina", tab);
        insert("Blazej", tab);
        insert("Emilia", tab);
        insert("Marta", tab);
        insert("Aaron", tab);
        insert("Katarzyna", tab);
        insert("Zuzanna", tab);
        insert("Zofia", tab);
        insert("Klara", tab);
        insert("Szymon", tab);
        insert("Janusz", tab);
        insert("Karol", tab);
        insert("Tadeusz", tab);
        insert("Maria", tab);
        wyswietl(tab);
    }
};
