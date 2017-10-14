#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Dane s¹ definicje:
const
max1 = 100;
max2 = 2000;
type
table = array[1..max1] of array[1..max2] of real;
Typ table opisuje tablicê zawieraj¹c¹ max1 wierszy po max2 elementów. Proszê napisaæ
funkcjê, która dla zmiennej typu table zwraca numer wiersza w którym najwiêksza wartoœæ
jest najmniejsza
*/
using namespace std;

int main()
{
    srand(time(NULL));
    const int max1 = 10, max2 = 20;
    int maxline[max1];

    for(int i=0; i<max1; i++)
    {
        maxline[i] = 0;
    }

    int tab[max1][max2];

    for(int i=0; i<max1; i++)
    {
        cout<<endl;
        for(int j=0; j<max2; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<" ";
            if(tab[i][j] > maxline[i])
            {
                maxline[i] = tab[i][j];
            }
        }
    }

    cout<<endl<<endl<<endl<<endl;

    int minline = 100;
    int line_number = 0;
    for(int i=0; i<max1; i++)
    {
        cout<<"Wartosc maksymalna w wierszu: "<< i <<" to "<<maxline[i]<<" "<<endl;
        if(maxline[i] < minline)
        {
            minline = maxline[i];
            line_number = i;
        }
    }
    cout<<endl<<endl;
    cout<<"Numer wiersza w ktorym najwieksza wartosc jest najmniejsza: "<<line_number<<", ta wartosc to: "<<minline<<endl;


    return 0;
}
