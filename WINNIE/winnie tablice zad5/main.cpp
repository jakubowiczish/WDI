#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dane s¹ deklaracje:
const
max = 20;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Proszê napisaæ funkcjê, która zwraca wartoœæ true je¿eli w zmiennej typu tablica istnieje
przynajmniej jedna para s¹siednich elementów, których suma jest równa œredniej
arytmetycznej wszystkich elementów tablicy.
*/
using namespace std;

const int N = 2;

bool average_pair(int tab[N][N])
{
    int sum = 0;
    double av = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            sum += tab[i][j];
        }
    }

    av = sum /(N*N);

    cout<<"Srednia tabeli to: "<<av<<endl;

    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<N-1; j++)
        {
            if(((tab[i][j] + tab[i][j+1]) == av) || ((tab[i][j] + tab[i+1][j]) == av))
            {
                //cout<<"TAK"<<endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand(time(NULL));
    int t[N][N];
/*  t[0][0] = 1;
    t[0][1] = 2;
    t[1][0] = 4;
    t[1][1] = 5; */
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            t[i][j] = rand() % 2;
            cout<<t[i][j]<<"\t";
        }
    cout<<endl<<endl;
    }

    cout<<average_pair(t);
}
