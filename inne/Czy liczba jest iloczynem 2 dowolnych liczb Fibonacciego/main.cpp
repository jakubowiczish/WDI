#include <iostream>
/*
Napisz program wczytuj¹cy liczbê naturaln¹ z klawiatury i odpowiadaj¹cy na pytanie,
czy liczba ta jest iloczynem dowolnych dwóch wyrazów ci¹gu Fibonacciego.
*/

using namespace std;

inline bool isFibonacci(unsigned long long i)
{
    unsigned long long Fibonacci1 = 0;
    unsigned long long Fibonacci2 = 1;

    while(Fibonacci2 <= i)
    {
        unsigned long long Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;

        if(Fibonacci2 == i) return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);

    unsigned long long n;
    cin >> n;

    bool flag = false;

    for(unsigned long long i=0; i < n; i++)
    {
        for(unsigned long long j=0; j < n; j++)
        {
            if((i*j == n) && isFibonacci(i) && isFibonacci(j))
                flag = true;
        }
    }

    if(flag)
        cout<<"Tak, liczba jest iloczynem 2 dowolnych wyrazow ciagu Fibonacciego"<<endl;
    else
        cout<<"Nie, liczba NIE jest iloczynem 2 dowolnych wyrazow ciagu Fibonacciego"<<endl;

    return 0;
}
