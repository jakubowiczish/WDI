#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
1. Mamy tablicê [1..max,1..max] of integer. Wyzeruj w niej wszystkie liczby które nie maj¹ w tablicy innej
liczby, która powsta³aby poprzez przestawienie jej cyfr. (uwa¿aj¹c na 1000 i 0100 - nie dziala)
*/
const int N = 3;
bool areMadeOfSameDigits(int a, int b);
void set_table(int tab[N][N]);
void zero_table(bool tab[N][N]);
void print_table(int tab[N][N]);

int main()
{
    int tab[N][N] = {{6, 4, 6}, {6, 10, 7}, {3,2,3}};
    bool should_be_zero[N][N];

    cout << "Zainicjalizowana tablica: " << endl;
    set_table(tab);
    zero_table(should_be_zero);

    bool found = false;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            found = false;
            for(int k=i; k < N; k++)
            {
                for(int m=j; m < N; m++)
                {
                    if((i != k || j != m) && areMadeOfSameDigits(tab[i][j],tab[k][m]))
                    {
                        found = true;
                        should_be_zero[k][m] = false;
                    }
                }
            }
            if(found)
            {
                should_be_zero[i][j] = false;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (should_be_zero[i][j])
            {
                tab[i][j] = 0;
            }
        }
    }
    cout << "Tablica po wyzerowaniu: " << endl;
    print_table(tab);
    return 0;
}

bool areMadeOfSameDigits(int a, int b)
{
    int digits1[10], digits2[10];
    for(int i=0; i < 10; i++)
    {
        digits1[i] = 0;
        digits2[i] = 0;
    }
    int x = a;
    int y = b;
    while(x > 0)
    {
        int ost = x%10;
        digits1[ost]++;
        x /= 10;
    }
    while(y > 0)
    {
        int ost = y%10;
        digits2[ost]++;
        y /= 10;
    }

    int counter = 0;
    for(int i=0; i < 10; i++)
    {
        if(digits1[i] == digits2[i])
        {
            counter++;
        }
        if(counter == 10)
            return true;
    }
    return false;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 10 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void zero_table(bool tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = true;
        }
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
