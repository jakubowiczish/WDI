#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
        return false;

    for(int i=2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int suma_cyfr(int n)
{
    int next = n;
    int sum = 0;
    while(next > 0)
    {
        sum += next % 10;
        next /= 10;
    }
    return sum;
}

int main()
{
    srand(time(NULL));
    const int N = 100;
    unsigned long long mainSum = 0;
    int tab[N];
    for(int i=0; i<N; i++)
    {
        tab[i] = rand() % 1000 + 1;
        cout<<"Indeks: "<<i<<", liczba: "<<tab[i]<<endl;
    }
    for(int i=0; i<N; i++)
    {
        if(!isPrime(i))
        {
            mainSum += suma_cyfr(tab[i]);
        }
    }
    cout<<"Suma cyfr liczb ktore stoja na indeksach ktore nie sa liczbami pierwszymi: "<<mainSum<<endl;

    return 0;
}
