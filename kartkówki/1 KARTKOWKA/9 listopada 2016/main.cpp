#include <iostream>
#include <cmath>
/*
Dane sa ciagi an, bn i cn okreslone nastepujaco:
an = 1 dla n = 1, 2 bn = 1 dla n = 1, 2, 3
an = an−1 + an−2 dla n > 2 bn = bn−1 + bn−2 + bn−3 dla n > 3
Wyrazy ciagu cn sa kolejnymi liczbami naturalnymi nalezacymi do ciagu an lub bn.
Ciagi te przyjmuja wartosci:
an : 1 1 2 3 5 8 13 21 ...
bn : 1 1 1 3 5 9 17 31 ...
cn : 1 2 3 5 8 9 13 17 ...
Prosze napisac program który wczytuje wprowadzona z klawiatury liczbe naturalna k
i wypisuje k-ty wyraz ciagu cn.
*/
//
using namespace std;

int main()
{
    int k, c = -1;
    cin>>k;
    int a_prev = 1, a = 1;
    int b_prev_prev = 1, b_prev = 1, b = 1;
    for(int i=0; i<k; i++)
    {
        c = min(a,b);
        if(a == c)
        {
            int next = a_prev + a;
            a_prev = a;
            a = next;
        }
        if(b == c)
        {
            int next = b_prev_prev + b_prev + b;
            b_prev_prev = b_prev;
            b_prev = b;
            b = next;
        }
    }
    cout<<c<<endl;
    return 0;
}

