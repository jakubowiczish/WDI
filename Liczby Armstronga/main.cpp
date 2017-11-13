#include <iostream>
#include <cmath>
/*
N-cyfrowa liczba Armstronga to liczba równa sumie N-tych poteg swoich cyfr. Prosze napisac
program, który znajduje wszystkie liczby Armstronga.
*/
using namespace std;
const int N = 100000000;

long long pot_szybkie(long long a, unsigned int n);

int counter_of_digits(int n)
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
int main()
{
    for(int i=0; i<N; i++)
    {
        int i2 = i;
        int sum = 0;
        while(i2 > 0)
        {
            sum += pot_szybkie((i2%10),counter_of_digits(i));
            i2 /= 10;
        }

        if(sum == i)
            cout<<i<<endl;
    }
    return 0;
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
