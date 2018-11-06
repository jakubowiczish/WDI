#include <iostream>

using namespace std;
/*
Dana jest tablica booli int t[N][N] reprezentująca szachownicę. Pole szachownicy ma
wartość true, jeżeli stoi na nim figura, a false, jeśli jest ono puste. Proszę napisać
funkcję która sprawdza czy istnieje droga skoczka przemieszczającego się z wiersza
0 do wiersza N-1. Skoczek może poruszać się tylko po polach pustych. Skoczek w
każdym ruchu powinien przybliżać się do N-1 wiersza. Funkcja ma zwrócić
najmniejszą możliwą liczbę ruchów. Skoczek może zacząć poruszać się z dowolnego
pustego pola z wiersza 0. N z zakresu 4...20.
*/
const int N = 9;
void print_table(bool tab[N][N]);
int ilosc_krokow_do_celu(int n, int w, int k);
bool mozliwe(int i, int w, int k, int &w1, int &k1);

bool tab[N][N] =
{
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
};

int main()
{
    print_table(tab);
    cout << ilosc_krokow_do_celu(0,0,0);
    return 0;
}

int ilosc_krokow_do_celu(int n, int w, int k) // n - ilosc krokow, w - wiersz, k - kolumna
{
    if(w == N-1)
        return 0;

    int najlepszy_ruch = -1;
    for(int i=0; i < 4; i++){
        int w1,k1;

        if(mozliwe(i,w,k,w1,k1)){
            int kroki = ilosc_krokow_do_celu(n+1,w1,k1);

            if((kroki != -1 && najlepszy_ruch == -1) || kroki < najlepszy_ruch){
                najlepszy_ruch = kroki;
            }
        }
    }
    if (najlepszy_ruch == -1)
        return -1;
    return najlepszy_ruch + 1;
}

bool mozliwe(int i, int w, int k, int &w1, int &k1)
{
    int dx[] = {2,1,-1,-2};
    int dy[] = {1,2,2,1};

    k1 = k + dx[i];
    w1 = w + dy[i];

    return ((k1 >= 0) and (k1 < N) and (w1 >=0) and (w1 < N) and !tab[w1][k1]);
}

void print_table(bool tab[N][N])
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
