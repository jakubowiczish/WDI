#include <iostream>

using namespace std;

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

bool is_comp(int a)
{
    for(int i = 2; i < a; i++)
    {
        if(a % i == 0)
            return true;
    }
    return false;
}

bool is_prime(int a)
{
    if(a == 0 || a == 1)
        return false;

    for(int i = 2; i < a; i++)
    {
        if(a % i == 0)
            return false;
    }

    return true;
}

int main()
{
    generate_fib();

    int tab[] = {4,8,4,8,16,8,12,13,7};
    int tab_size = sizeof(tab)/sizeof(int);

    int prime_count = 0;

    for(int i = 0; i < tab_size; i++)
    {
        if(is_fib(i))
        {
            if(!is_comp(tab[i]))
            {
                cout << "Liczba " << tab[i] << " na indeksie " << i << endl;
                return 1;
            }
        }
        else
        {
            if(is_prime(tab[i]))
                prime_count++;
        }
    }

    if(prime_count == 0)
    {
        cout << "Nie znaleziono ani jednej liczby pierwszej na nie-fib indeksach" << endl;
        return 1;
    }



    return 0;
}
