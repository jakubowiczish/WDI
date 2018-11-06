#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica int t[N][N] wype³niona liczbami naturalnymi. Z danego pola mo¿emy
wykonywaæ ruch w prawo lub w dó³, pod warunkiem, ¿e przechodzimy na pole o wiêkszej
wartoœci.
(a) Napisaæ funkcjê, która sprawdzi czy mo¿na przejœæ z pola [0,0] na pole [N-1,N-1]
(b) wypisaæ drogê przejœcia
*/
using namespace std;
const int N = 6;

bool droga(int tab[N][N], int w, int k);
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);
bool czy_moge_w_dol(int w, int k);
bool czy_moge_w_prawo(int w, int k);

int tab[N][N]=
    {
        {1,1,1,1,1,1 },
        {2,3,4,5,6,1 },
        {1,1,1,1,7,1 },
        {1,1,6,7,8,1 },
        {1,1,1,8,9,1 },
        {1,1,1,1,10,11}
    };

int main()
{
    print_table(tab);
    cout << droga(tab,0,0);
    return 0;
}

bool czy_moge_w_dol(int w, int k)
{
    return (w < N-1 && tab[w+1][k] > tab[w][k]);
}
bool czy_moge_w_prawo(int w, int k)
{
    return (k < N-1 && tab[w][k+1] > tab[w][k]);
}

bool droga(int tab[N][N], int w, int k)
{
    if(w == N-1 && k == N-1)
        return true;
    if(czy_moge_w_dol(w,k) && czy_moge_w_dol(w,k))
        return droga(tab,w+1,k) || droga(tab,w,k+1);
    if(czy_moge_w_dol(w,k))
        return droga(tab,w+1,k);
    if(czy_moge_w_prawo(w,k))
       return droga(tab,w,k+1);

    return false;
}

void print_table(int tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
void set_table(int tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = i + j;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
