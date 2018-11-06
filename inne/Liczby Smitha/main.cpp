#include <iostream>
#include <cmath>
/*
Liczba Smitha to taka, której suma cyfr jest równa sumie cyfr wszystkich liczb wystêpuj¹cych
w jej rozk³adzie na czynniki pierwsze. Na przyk³ad: 85=5*17, 8+5=5+1+7.
Napisaæ program wypisuj¹cy liczby Smitha mniejsze od 1000000.
*/

// NA WIKIPEDII JEST JESZCZE ZE TA LICZBA JEST ZLOZONA
using namespace std;

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

int sumOfDigits(int n)
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

int sumOfDigitsOfFactors(int n) // suma cyfr czynnikow pierwszych
{
    int k = 2;
    int sum = 0;
    while(n > 1)
    {
        while(n%k == 0)
        {
            sum += sumOfDigits(k);
            n /= k;
        }
        ++k;
    }
    // cout<<"suma: "<<sum<<endl;
    return sum;
}

int main()
{
    const int N = 1000000;
    for(int i=0; i<N; i++)
    {
        if(!isPrime(i))
        {
            if(sumOfDigits(i) == sumOfDigitsOfFactors(i))
                cout<<i<<endl;
        }
    }
    return 0;
}
