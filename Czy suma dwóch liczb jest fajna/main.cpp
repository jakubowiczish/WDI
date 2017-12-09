#include <iostream>
#include <ctime>
#include <cstdlib>
/*
. Liczba jest fajna, gdy jej wartość otrzymujemy przez k-krotne podwojenie pewnej nieparzystej liczby pierwszej p,
przy czym k również jest liczbą pierwszą.
Np. liczbami fajnymi są: 40=5*2*2*2, 12=3*2*2.
Dana jest tablica typu tab = array[1..max] of integer zawierająca liczby naturalne.
Napisz funkcję, która stwierdza, czy w tablicy są takie dwie liczby, których suma jest fajna.
*/
using namespace std;
const int N = 10;
bool isCool(int n);
bool isPrime(int n);
void set_table(int tab[N]);
bool areCoolInTab(int tab[N]);

int main()
{
    int tab[N];
    set_table(tab);
    cout << endl;
    cout << areCoolInTab(tab);
    return 0;
}

bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

bool isCool(int n)
{
    for(int i=1; i <= n; i++)
    {
        int k = 0;
        int temp = n;
        while(temp%2 == 0)
        {
            ++k;
            temp /= 2;
            if(isPrime(temp) && isPrime(k))
                return true;
        }
    }
    return false;
}

bool areCoolInTab(int tab[N])
{
    int sum = 0;
    for(int i=0; i < N; i++)
    {
        for(int j=i+1; j < N-1; j++)
        {
            sum = tab[i] + tab[j];
            if(isCool(sum))
                return true;
        }
    }
    return false;
}

void set_table(int tab[N])
{
    srand(time(NULL));
    for(int i=0; i < N; i++){
        tab[i] = rand() % 50 + 1;
        cout << tab[i] << " ";
    }
}
