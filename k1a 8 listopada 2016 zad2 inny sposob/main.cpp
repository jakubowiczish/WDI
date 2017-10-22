#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

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
        najw[i] = 0; // wyzerowanie tablicy na 10 najwiekszych liczb
        cout<<tab[i]<<" ";
    }
    cout<<endl<<endl;
    for(int i=0; i<MAX; i++)
    {
        if(tab[i] > najw[i])
        {
            najw[i] = tab[i];
        }
    }
    quicksort(najw,0,MAX-1);
    for(int i=0; i<MAX; i++)
    {
        cout<<najw[i]<<" ";
    }

    return 0;
}
