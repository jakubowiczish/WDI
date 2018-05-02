#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Dana jest du¿a tablica typu tab=array[1..n] of integer. Proszê napisaæ
funkcjê, która zwraca informacjê, czy w tablicy zachodzi nastêpuj¹cy
warunek: „wszystkie elementy, których indeks jest elementem ci¹gu
Fibonacciego s¹ liczbami z³o¿onymi, a wœród pozosta³ych przynajmniej jedna
jest liczb¹ pierwsz¹”.
*/
using namespace std;
const int N = 10;

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

bool isFibobacci(int n)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= n)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;

        if(Fibonacci2 == n)
            return true;
    }
    return false;
}
int main()
{
    int tab[N];
    srand(time(NULL));
    // INICJALIZACJA TABLICY
    for(int i=0; i<N; i++)
    {
        tab[i] = rand() % 50 + 1;
        cout<<tab[i]<<" ";
    }

    //LICZNIKI, JEDEN ZLICZA ILE JEST LICZB KTORYCH INDEKSY SA LICZBAMI FIBONACCIEGO
    //DRUGI SRPAWDZA CZY LICZBY NA TYCH INDEKSACH SA ZLOZONE, JESLI TAK TO ALLCOMPLEX = TRUE
    int counterFibonacci = 0;
    int counterComplex = 0;

    bool allComplex = false;

    for(int i=0; i<N; i++)
    {

        if(isFibobacci(i))
        {
            counterFibonacci++;
            if(isComplex(tab[i]))
                counterComplex++;
        }
    }

    if(counterComplex == counterFibonacci)
        allComplex = true;

    int counterPrime = 0;

    //SZUKAMY, CZY CHOCIAZ JEDEN ELEMENT KTOREGO INDEKS NIE JEST LICZBA FIBONACCIEGO
    //JEST LICZBA PIERWSZA
    bool PrimeElement = false;

    for(int i=0; i<N; i++)
    {
        if(allComplex)
        {
            if(!isFibobacci(i))
            {
                if(isPrime(tab[i]))
                    counterPrime++;
                if(counterPrime >= 1)
                {
                    PrimeElement = true;
                    break;
                }
            }
        }
    }

    if(allComplex && PrimeElement)
    {
        cout<<"Tak, wszystkie elementy, ktorych indeks jest elementem ciagu"<<endl;
        cout<<"Fibonacciego sa liczbami zlozonymi, a wsrod pozostalych przynajmniej"<<endl;
        cout<<"jedna jest liczba pierwsza"<<endl;
    }

    else
        cout<<"NIE"<<endl;
    return 0;
}
