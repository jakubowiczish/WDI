#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica int t*MAX+*MAX+ wypełniona liczbami naturalnymi. Proszę napisad funkcję który odpowiada
na pytanie, czy istnieje wiersz w tablicy w którym każda z liczb zawiera przynajmniej jedna cyfrę parzystą.
*/
using namespace std;
const int N = 5;

bool isEvenOneEven(int tab[N][N]);
void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);

    cout << isEvenOneEven(tab);
    return 0;
}

bool isEvenOneEven(int tab[N][N])
{
    int rows[N];
    for(int i=0; i < N; i++)
        rows[i] = 0;

    for(int i=0; i < N; i++)
    {
        int counter_rows = 0; /// zlicza wystapienia w calych wierszach

        for(int j=0; j < N; j++)
        {
            int counter = 0; /// zlicza wystapienia w poszczegolnych komorkach

            int k = tab[i][j];
            while(k > 0){
                if((k%10)%2 == 0){
                    counter++;
                }
                k /= 10;
            }
            if(counter > 0){
                counter_rows++;
            }
        }
        if(counter_rows == N){
            return true;
        }
    }
    return false;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout << tab[i][j] << '\t';
        }
        cout << endl << endl;
    }
}
