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
void findBiggestSum(int tab[N][N]);

int main()
{
    int tab[N][N];
    cout<<"Original table: " << endl << endl;
    set_table(tab);
    findBiggestSum(tab);
}

bool isIndexValid(int i, int j)
{
    if(i >= 0 and j >= 0 and i < N and j < N)
        return true;
    return false;
}

void findBiggestSum(int tab[N][N])
{
    int d_x[] = {-1,0,1,-1,1,-1,0,1};
    int d_y[] = {-1,-1,-1,0,0,1,1,1};
    int sum[N][N];
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            sum[i][j] = 0;

    int row = 0, column = 0;
    int MaxSum = 0;
    cout << "Table of sums: " << endl << endl;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            for(int n_id=0; n_id < 8; n_id++)
            {
                if(isIndexValid(i + d_x[n_id],j + d_y[n_id]))
                {
                    sum[i][j] += tab[i + d_x[n_id]][j + d_y[n_id]];
                    if(sum[i][j] > MaxSum){
                        MaxSum = sum[i][j];
                        row = i;
                        column = j;
                    }
                }
            }
            cout << sum[i][j] <<" ";
        }
        cout << endl << endl;
    }
    cout << "Row: " << row << endl;
    cout << "Column: " << column << endl;
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
