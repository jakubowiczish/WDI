#include <iostream>
/*
Zad. 1 Dana jest du¿a tablica typu tab=array[1..n] of integer. Proszê napisaæ funkcjê, która
zwraca informacjê, czy w tablicy zachodzi nastêpuj¹cy warunek: „wszystkie elementy, których
indeks jest elementem ci¹gu Fibonacciego s¹ liczbami z³o¿onymi, a wœród pozosta³ych
przynajmniej jedna jest liczb¹ pierwsz¹”.
*/
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i < n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

const int fib_len = 30;

unsigned int fib[fib_len];

void generate_fib()
{
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < fib_len; i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
    }
}

bool is_fib(int a)
{
    for(int i = 0; i < fib_len; i++)
    {
        if(a == fib[i])
            return true;
    }
    return false;
}


int main()
{
    const int N = 10;
    int tab[N];
    tab[0] = 8;
    tab[1] = 6;
    tab[2] = 8;
    tab[3] = 8;
    tab[4] = 8;
    tab[5] = 12;
    tab[6] = 8;
    tab[7] = 13;
    tab[8] = 8;
    tab[9] = 8;

    int licznik = 0, licznik2 = 0; // licznik - composite(zlozone) licznik2 - prime(pierwsze)
    for(int i=0; i<N; i++)
    {
        if(is_fib(i) == true) // dla czytelnosci
        {
            if(isPrime(tab[i]) == false)
            {
                licznik += 0; // jesli liczba jest zlozona nie robimy nic
            }
            else
            {
                licznik++; // jesli jest pierwsza zwiekszamy licznik
                cout << "liczba niezlozona na " << i << " " << tab[i] << endl;
            }
        }
        else
        {
            if(isPrime(tab[i]) == true)
            {
                licznik2++;  // jesli jest chociaz jedna liczba pierwsza zwiekszamy licznik
            }
        }
    }

    if(licznik == 0 && licznik2 > 0)
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }

    return 0;
}
