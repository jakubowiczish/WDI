#include <iostream>
#include <ctime>
#include <cstdlib>

/*
W szachownicy o wymiarach 8x8 każdemu z pól przypisano liczbę naturalną.
Na ruchy króla nałożono dwa ograniczenia: król może przesunąd się na jedno z 8 sąsiednich pól
jeżeli ostatnia cyfra liczby na polu na którym stoi jest mniejsza od pierwszej cyfry liczby pola docelowego,
oraz w drodze do obranego celu (np. narożnika) król nie może wykonad ruchu, który powoduje oddalenie go od celu.
Dana jest globalna tablica int t*8+*8+ wypełniona liczbami naturalnymi reprezentująca szachownicę.
Lewy górny narożnik ma współrzędne w=0 i k=0.
Proszę napisad funkcję sprawdzającą czy król może dostad się z pola w,k do prawego dolnego narożnika .
*/
using namespace std;
const int N = 5;

void set_table(int tab[N][N]);
void print_table(int tab[N][N]);
int rever(int n);

bool czy_moge_w_prawo(int tab[N][N], int w, int k);
bool czy_moge_w_dol(int tab[N][N], int w, int k);
bool czy_moge_na_skos(int tab[N][N], int w, int k);

bool droga(int tab[N][N], int w, int k);

int main()
{
    int tab[N][N];
    set_table(tab);
    cout << droga(tab,0,0);
    return 0;
}

bool czy_moge_w_prawo(int tab[N][N], int w, int k)
{
    return (k < N -1 and (tab[w][k]%10) < ((rever(tab[w][k+1]))%10));
}

bool czy_moge_w_dol(int tab[N][N], int w, int k)
{
    return (w < N -1 and (tab[w][k]%10) < ((rever(tab[w+1][k]))%10));
}

bool czy_moge_na_skos(int tab[N][N], int w, int k)
{
    return (k < N -1 and w < N -1  and (tab[w][k]%10) < ((rever(tab[w+1][k+1]))%10));
}

bool droga(int tab[N][N], int w, int k)
{
    if (w >= N || k >= N)
        return false;
    if(w == N-1 and k == N-1)
        return true;
    if(czy_moge_w_dol(tab,w,k) and czy_moge_w_prawo(tab,w,k) and czy_moge_na_skos(tab,w,k)){
        return droga(tab,w+1,k) || droga(tab,w,k+1) || droga(tab,w+1,k+1);
    }
    if(czy_moge_w_dol(tab,w,k) and czy_moge_w_prawo(tab,w,k)){
        return droga(tab,w+1,k) || droga(tab,w,k+1);
    }
    if(czy_moge_w_dol(tab,w,k) and czy_moge_na_skos(tab,w,k)){
        return droga(tab,w+1,k) || droga(tab,w+1,k+1);
    }
    if(czy_moge_w_prawo(tab,w,k) and czy_moge_na_skos(tab,w,k)){
        return droga(tab,w,k+1) || droga(tab,w+1,k+1);
    }
    if(czy_moge_w_dol(tab,w,k))
        return droga(tab,w+1,k);
    if(czy_moge_w_prawo(tab,w,k));
        return droga(tab,w,k+1);
    if(czy_moge_na_skos(tab,w,k))
        return droga(tab,w+1,k+1);

}

int rever(int n)
{
    int temp = 0;
    while(n > 0){
        temp = temp*10 + n%10;
        n /= 10;
    }
    return temp;
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
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand()%5 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
