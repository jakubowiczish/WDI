#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
/*
Proszê napisaæ program, który wype³nia tablicê int tab[MAX] liczbami pseudolosowymi
z zakresu [1 .. 1000], a nastêpnie wyznacza i wypisuje sumê 10 najwiêkszych elementów
z tablicy.
Uwagi:
- tablica tab zajmuje ponad po³owê dostêpnej pamiêci na dane i nie mo¿e ulec zmianie
*/

using namespace std;
void quicksort(int *tablica, int lewy, int prawy);

int main()
{
    const int MAX = 15;
    int tab[MAX];
    int najw[10];
    for(int i=0; i<MAX; i++)
    {
        tab[i] = rand() % 1000 + 1;
    }
    for(int i=0; i<MAX; i++)
    {
         // wyzerowanie tablicy na 10 najwiekszych liczb
        cout<<tab[i]<<" ";
        for(int j=0; j<10; j++)
        {
            najw[j] = 0;
        }
    }
    cout<<endl<<endl;
    int najwiekszy = 0;
    for(int i=0; i<MAX; i++)
    {
        if(tab[i] > najw[0])
            najw[0] = tab[i];

        for(int j=1; j<10 and najw[j] < tab[i]; j++)
        {
            najw[j-1] = najw[j];
            najw[j] = tab[i];
        }
    }
    //quicksort(najw,0,MAX-1);

    long sum = 0;
    for(int i=0; i<10; i++)
    {
        cout<<najw[i]<<" ";
        sum += najw[i];
    }
    cout<<endl<<"Suma: "<<sum<<endl;

    return 0;
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}
