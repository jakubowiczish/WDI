#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
Dana jest tablica int t*MAX+*MAX+ wype³niona liczbami naturalnymi. Proszê napisad funkcjê która zwraca
wiersz i kolumnê dowolnego elementu, dla którego iloraz sumy elementów w kolumnie w którym le¿y
element do sumy elementów wiersza w którym le¿y element jest najwiêksza.
*/
const int N = 3;
void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    int sum_col[N], sum_row[N];
    for(int i=0; i<N; i++)
    {
        sum_col[i] = 0;
        sum_row[i] = 0;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            sum_col[i] += tab[j][i];
            sum_row[i] += tab[i][j];
        }
    }

    int max_col = 0, min_row = 10000;
    int X = 0, Y = 0;
    for(int i=0; i<N; i++)
    {
        if(sum_col[i] > max_col)
        {
            max_col = sum_col[i];
            X = i;
        }
        if(sum_row[i] < min_row)
        {
            min_row = sum_row[i];
            Y = i;
        }
    }
    cout<<"X: "<<X<<" Y: "<<Y<<endl;

    return 0;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
