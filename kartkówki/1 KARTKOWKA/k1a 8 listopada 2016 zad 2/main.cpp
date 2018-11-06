#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
/*
Proszê napisaæ program, który wype³nia tablicê int tab[MAX] liczbami pseudolosowymi
z zakresu [1 .. 1000], a nastêpnie wyznacza i wypisuje sumê 10 najwiêkszych elementów
z tablicy.
Uwagi:
- tablica tab zajmuje ponad po³owê dostêpnej pamiêci na dane i nie mo¿e ulec zmianie
*/
using namespace std;

int main()
{
    const int MAX = 20;
    int tab[MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
    {
        tab[i] = (rand() % 1000) + 1;
    }
    int licznik = 10;
    sort(tab,tab+20);
    for(int i=0; i<MAX; i++)
        cout<<tab[i]<<" ";
    long suma = 0;
    for(int i=MAX/2; i<MAX; i++)
    {
        suma += tab[i];
    }
    cout<<suma<<endl;


    return 0;
}
