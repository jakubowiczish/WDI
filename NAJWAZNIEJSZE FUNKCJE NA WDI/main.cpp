#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);
bool isComplex(int n);
void quicksort(int *tablica, int lewy, int prawy);
bool isFibonacci(int i);
int nextFibonacci(int i);
void zamiana(int N, int p);
int numberOfDigits(int n);
long long pot_szybkie(long long a, unsigned int n);
void rozklad_na_czynniki_pierwsze_fast(int n);
void rozklad_na_czynniki_pierwsze_slow(int n);
int LCD (int a, int b); //largest common divisor
int silnia(int n);

int main()
{
    rozklad_na_czynniki_pierwsze_slow(2468938);
    cout<<endl;
    rozklad_na_czynniki_pierwsze_fast(2468938);
    cout<<endl;
    cout<<pot_szybkie(2,62);
    cout<<endl;
    cout<<numberOfDigits(12345);

    cout<<endl<<silnia(9);
    return 0;
}

int LCD (int a, int b) //largest common divisor
{
    int c;
    while(b != 0)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int silnia(int n)
{
    long long result = 1;
    for(int i=1; i<=n; i++)
    {
        result *= i;
    }
    return result;
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

bool isComplex(int n)
{
    if(n < 2)
        return false;
    if(isPrime(n))
        return false;

    return true;
}

long long pot_szybkie(long long a, unsigned int n)
{
    long long w = 1;

    while(n>0)
    {
        if (n%2 == 1) //jesli bit jest = 1
            w *= a;

        a*= a;
        n/=2; //skrócenie o jeden bit
    }
    return w;
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}

bool isFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i) return true;
    }
    return false;
}

int nextFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i)
            return Fibonacci1 + Fibonacci2;
    }
    return -1;
}

void rozklad_na_czynniki_pierwsze_slow(int n)
{
    int k = 2;

    while(n>1)
    {
        while(n%k == 0) //dopóki liczba jest podzielna przez k
        {
            cout<<k<<" ";
            n/=k;
        }
        ++k;
    }
}

void rozklad_na_czynniki_pierwsze_fast(int n)
{
    int pierw = sqrt(n);

    int k = 2; //ustawiamy k na pierwsz¹ liczbê pierwsz¹

    while(n > 1 && k <= pierw)
    {
        while(n%k == 0) //dopóki liczba jest podzielna przez k
        {
            cout<<k<<" ";
            n/=k;
        }
        ++k;
    }

    if(n>1)
        cout<<n;
}

void zamiana(int N, int p) // N - liczba ktora chcemy zamienic, p - podstawa systemu
{
    if(N == 0) return;

    int reszta = N % p;
    N = N/p;
    zamiana(N,p); // rekurencja zeby nie uzywac tablic
    if(reszta < 10)
    {
        cout<<reszta;
    }
    else
    {
        char litera = reszta + 55; // kod ascii dla reszt 11 - 15
        cout<<litera;
    }
}


int numberOfDigits(int n)
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
