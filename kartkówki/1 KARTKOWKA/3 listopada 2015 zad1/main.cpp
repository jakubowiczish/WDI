#include <iostream>
/*
Proszê napisaæ program, który wczytuje liczbê naturaln¹ A i odpowiada na pytanie: ,,czy w którymkolwiek
z systemów o podstawie 2-16, wszystkie cyfry liczby A zapisanej w tym systemie, s¹ liczbami pierwszymi?".
*/

using namespace std;

bool isPrimeDigit(int n)
{
    const int PRIMES[6] = {2,3,5,7,11,13};

    for(int i=0; i<6; i++)
    {
        if(n == PRIMES[i])
        {
            return true;
        }
    }

    return false;
}

bool checkNumber(int n)
{
    for(int base=2; base<=16; base++)
    {
        int temp = n;
        bool allDigitsPrime = true;

        while(temp != 0 && allDigitsPrime)
        {
            allDigitsPrime = isPrimeDigit(temp % base);
            temp /= base;
        }

        if(allDigitsPrime)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<checkNumber(21);
    return 0;
}
