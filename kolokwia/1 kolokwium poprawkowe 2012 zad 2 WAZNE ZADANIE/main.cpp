#include <iostream>
#include <cmath>
/*  Napisz procedurê, która jako argument przyjmuje liczbê ca³kowit¹ i wypisuje wszystkie co najmniej
dwucyfrowe liczby pierwsze, powstale poprzez wykreœlenie z liczby pierwotnej co najmniej jednej cyfry.
*/

using namespace std;

int counterOfDigits(int n)
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
    for(int i=2; i*i<=n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

void numbers(int n)
{
    int i2, n2, r;

    for(int i=0; i<pow(2,counterOfDigits(n)); i++) // sprawdzanie czy liczby pozostale po wykresleniu sa pierwsze i potem ich wypisanie
    {
        i2 = i;
        n2 = n;
        r = 0;

        int multip = 1;

        while(i2 > 0)
        {
            if(i2 % 2 == 1)
            {
                r += (n2 % 10) * multip;
                multip *= 10;
            }

            //aktualizacja warunku
            n2 = n2/10;
            i2 = i2/2;
        }

        if(isPrime(r) && counterOfDigits(r) >= 2) // wypisywanie tych liczb
            cout<<r<<endl;
    }
}

int main()
{
    int a;
    cin>>a;
    numbers(a);

    return 0;
}
