#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
Dana jest tablica int t[N][N] wype³niona przypadkowymi wartoœciami.
Proszê napisad funkcjê, która dla zmiennej typu tablica zwraca numer wiersza w którym wystêpuje
najd³u¿szy spójny fragment z³o¿ony z liczb o tej samej wartoœci.
W przypadku kilku fragmentów o tej samej d³ugoœci nale¿y zwrócid pozycjê pierwszego z nich.
*/
const int N = 3;
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);
int number_of_row(int tab[N][N]);

int main()
{
    int t[N][N];
    //set_table(tab);
    t[0][0]=5;
    t[0][1]=6;
    t[0][2]=5;
    t[1][0]=12;
    t[1][1]=12;
    t[1][2]=12;
    t[2][0]=25;
    t[2][1]=44;
    t[2][2]=23;
    print_table(t);
    cout << number_of_row(t);
    return 0;
}

int number_of_row(int tab[N][N])
{
    int MaxLength = 0;
    int row = 0;
    for(int i=0; i < N; i++)
    {
        int length = 1;

        for(int j=0; j < N; j++)
        {
            if(tab[i][j] == tab[i][j+1])
            {
                length++;
            }
            else
            {
                if(length > MaxLength)
                {
                    MaxLength = length;
                    row = i;
                }
                length = 1;
            }
            cout << "Dlugosc: " << length << endl;


        }
    }
    return row;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
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

