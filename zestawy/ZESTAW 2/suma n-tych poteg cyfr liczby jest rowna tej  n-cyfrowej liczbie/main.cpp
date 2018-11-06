#include <iostream>
#include <cmath>
using namespace std;

/*
Napisaæ program znajduj¹cy wszystkie liczby N-cyfrowe dla
których suma N-tych potêg cyfr liczby jest równa tej liczbie,
np. 153=1^3+5^3+3^3.
*/

/*inline unsigned long long wlasnyPow(unsigned long long podstawa, int index) // NORMALNY POW NIE DZIALA, WTF
{
    unsigned long long result = 1;
    for(int i=0; i<index; i++)
        result *= podstawa;

    return result;
}*/

inline long long pot_szybkie(long long a, unsigned int n)
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

inline int counterOfDigits(unsigned long long n)
{
    unsigned long long next = n;
    int counter = 0;

    while(next > 0)
    {
        counter++;
        next /= 10;
    }
    return counter;
}

inline void check(unsigned long long n)
{
    unsigned long long next = n;

    unsigned long long sum = 0;

    int index = counterOfDigits(n);
    while(next > 0)
    {
        int ost = next % 10;
        sum += pot_szybkie(ost,index);
        next /= 10;
    }

    if(sum == n)
        cout<<n<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned long long a;
    cin >> a;

    for(unsigned long long i=0; i <= a; i++)
    {
        check(i);
    }

    return 0;
}
