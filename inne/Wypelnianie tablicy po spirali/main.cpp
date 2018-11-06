#include <iostream>
using namespace std;
/*
. Dana jest tablica int t*MAX+*MAX+. Proszê napisad funkcjê wype³niaj¹c¹ tablicê liczbami naturalnymi po
spirali.
*/
const int N = 5;

void tablica_po_spirali(int tab[N][N], int a1, int r);
void print_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    tablica_po_spirali(tab,2,4);
    print_table(tab);
    return 0;
}

void tablica_po_spirali(int t[N][N], int a1, int r)
{
    bool doPrzodu = true;
    int dlugosc = N-1;
    int i=0, j=0;

    for(int k=0; k<dlugosc; k++)
    {
        t[i][j] = a1;
        a1 += r;
        doPrzodu ? j++ : j--;
    }

    for(; dlugosc > 0; dlugosc--)
    {
        for(int k=0; k<dlugosc; k++)
        {
            t[i][j] = a1;
            a1 += r;
            doPrzodu ? i++ : i--;
        }

        doPrzodu = !doPrzodu;

        for(int k=0; k<dlugosc; k++)
        {
            t[i][j] = a1;
            a1 += r;
            doPrzodu ? j++ : j--;
        }
    }
    t[i][j] = a1;
}

void print_table(int tab[N][N])
{
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
