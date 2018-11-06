#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Dana jest tablica int t[MAX][MAX],wype³niona liczbami naturalnymi. Proszê napisad funkcjê która
odpowiada na pytanie, czy w tablicy ka¿dy wiersz zawiera co najmniej jedn¹ liczb¹ z³o¿on¹ wy³¹cznie z cyfr
bêd¹cych liczbami pierwszymi
*/
using namespace std;
const int N = 3;

void set_table(int tab[N][N]);
bool areAllDigitsPrime(int tab[N][N]);
int counter_of_digits(int n);
bool isPrime(int n);

int main()
{
    int tab[N][N];
    set_table(tab);
    cout<<areAllDigitsPrime(tab);

    return 0;
}

bool areAllDigitsPrime(int tab[N][N])
{
    int flags[N];
    // tablica przechowujaca informacje o ilosci
    // liczb zlozonych wylacznie z cyfr pierwszych w poszczegolnych wierszach
    for(int i=0; i<N; i++)
        flags[i] = 0;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int counter = 0;
            int k = tab[i][j];
            int digits = counter_of_digits(tab[i][j]);

            while(k > 0)
            {
                if(isPrime(k%10))
                {
                    counter++;
                    if(counter == digits)
                        flags[i]++;
                }
                k/=10;
            }
        }
    }
    int counter2 = 0;
    for(int i=0; i<N; i++)
    {
        if(flags[i] != 0)
            counter2++;
    }
    if(counter2 == N)
        return true;

    return false;
}

int counter_of_digits(int n)
{
    int next = n;
    int counter = 0;
    while(next > 0)
    {
        counter++;
        next /= 10;
    }
    return counter;
}
bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <=n; i++)
    {
        if(n%i ==0)
            return false;
    }
    return true;
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
