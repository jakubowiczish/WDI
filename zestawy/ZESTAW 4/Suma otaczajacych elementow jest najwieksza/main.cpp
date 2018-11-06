#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica int t*MAX+*MAX+ wype³niona liczbami naturalnymi. Proszê napisad funkcjê która zwraca
wiersz i kolumnê dowolnego elementu, dla którego suma otaczaj¹cych go elementów jest najwiêksza.
*/
using namespace std;
const int N = 5;
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    cout<<"Pierwotna tablica: "<<endl;
    set_table(tab);

    int sum[N][N];
    for(int x=0; x<N; x++)
    {
        for(int y=0; y<N; y++)
        {
            sum[x][y] = 0;
        }
    }
    for(int x=0; x<N; x++)
    {
        for(int y=0; y<N; y++)
        {
            if(x > 0 && y > 0 && x < N-1 && y < N-1)
            {
                sum[x][y] = tab[x-1][y-1] + tab[x-1][y] + tab[x-1][y+1] + tab[x][y-1] + tab[x][y+1] + tab[x+1][y-1] + tab[x+1][y] + tab[x+1][y+1];
            }
            else if(y == 0 && x != 0 && x != N-1)
            {
                sum[x][0] = tab[x-1][0] + tab[x-1][1] + tab[x][1] + tab[x+1][0] + tab[x+1][1];
            }
            else if(y == N-1 && x != 0 && x != N-1)
            {
                sum[x][N-1] = tab[x-1][N-1] + tab[x-1][N-2] + tab[x][N-2] + tab[x+1][N-2] + tab[x+1][N-1];
            }
            else if(x == 0 && y != 0 && y != N-1)
            {
                sum[0][y] = tab[0][y-1] + tab[0][y+1] + tab[1][y-1] + tab[1][y] + tab[1][y+1];
            }
            else if(x == N-1 && y != 0 && y != N-1)
            {
                sum[N-1][y] = tab[N-1][y-1] + tab[N-1][y+1] + tab[N-2][y-1] + tab[N-2][y] + tab[N-2][y+1];
            }

        }
    }
    // elementy na rogach
    sum[0][0] = tab[0][1] + tab[1][0] + tab[1][1];
    sum[N-1][N-1] = tab[N-2][N-2] + tab[N-1][N-2] + tab[N-2][N-1];
    sum[0][N-1] = tab[0][N-2] + tab[1][N-1] + tab[1][N-2];
    sum[N-1][0] = tab[N-2][0] + tab[N-2][1] + tab[N-1][1];

    cout<<"Tablica sum otaczajacych elementow: "<<endl;
    print_table(sum);

    int maxSum = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(sum[i][j] > maxSum)
                maxSum = sum[i][j];
        }
    }
    cout<<"maxSum: "<<maxSum<<endl;
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
