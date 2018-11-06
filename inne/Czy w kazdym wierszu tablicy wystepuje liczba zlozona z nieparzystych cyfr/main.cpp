#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
Dana jest tablica int t[MAX][MAX] wype³niona liczbami naturalnymi. Proszê napisad funkcjê który odpowiada
na pytanie, czy w ka¿dym wierszu tablicy wystêpuje co najmniej jedna liczba z³o¿ona wy³¹cznie z
nieparzystych cyfr.
*/
const int N = 2;

bool areAllOdd(int tab[N][N]);
int counter_of_digits(int n);
void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);

    cout<<areAllOdd(tab);
    return 0;
}

bool areAllOdd(int tab[N][N])
{
    int flags[N]; // tablica mowiaca o tym, czy w kazdym wierszu jest chociaz jedna liczba z cyframi nieparzystymi
    for(int i=0; i<N; i++) // N - ilosc wierszy
        flags[i] = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int k = tab[i][j];
            int digits = counter_of_digits(k);
            int counter = 0;

            while(k > 0)
            {
                if((k%10)%2 != 0) /// zlicza cyfry nieparzyste danej liczby w tablicy, jesli liczba cyfr nieparzystych
                {                 /// rowna sie ilosci cyfr calej liczby, dodajemy ilosc tych liczb w rzedzie do tablicy flags
                    counter++;
                    if(counter == digits)
                    {
                        flags[i]++;
                    }
                }
                k/=10;
            }
        }
    }
    int counter2 = 0; // zlicza ilosc wystapien w tablicy flags
    // ta tablica przechowuje ilosc liczb zlozonych z samych cyfr nie parzystych w danym rzedzie
    for(int i=0; i<N; i++)
    {
        if(flags[i] > 0)
            counter2++;
        if(counter2 == N)
            return true;
    }

    return false;
}

int counter_of_digits(int n)
{
    int next = n;
    int counter = 0;
    while(next > 0)
    {
        counter++;
        next/=10;
    }
    return counter;
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
