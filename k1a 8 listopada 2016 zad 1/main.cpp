#include <iostream>
#include <cmath>
/*
Dane są dwa ciągi określone następująco:
a1 = 1 an = an−1 + bn/3
b1 = 2 bn = bn−1 + an−1
Proszę napisać program, który wczytuje liczbę naturalną k i odnajduje wyraz należący do
jednego z ciągów o wartości najbliższej k. Program powinien wypisać numer znalezionego
wyrazu i ciąg z którego on pochodzi. Jeżeli więcej niż jeden wyraz jest jednakowo odległy
od k, należy wybrać ten o mniejszym numerze.
Uwagi:
- czas na rozwiązanie obu zadań wynosi 30 minut
- oceniane będą: czytelność, poprawność i efektywność rozwiązań
- za rozwiązanie zadania można otrzymać maksymalnie 5 pkt.
*/
using namespace std;

int main()
{
    int k;
    cin>>k;
    double a = 1;
    double b = 2;
    double best = 1; // najmniejsza odleglosc
    char bestchoice = 'a';
    while(a <= k || b <= k)
    {
        if(fabs(a - k) < fabs(best - k))
        {
            best = a;
            bestchoice = 'a';
        }
        if(fabs(b - k) < fabs(best - k))
        {
            best = b;
            bestchoice = 'b';
        }
        b = b + a;
        a = a + b/3.0;
    }
    if(fabs(a - k) < fabs(best - k))
    {
        best = a;
        bestchoice = 'a';
    }
    if(fabs(b - k) < fabs(best - k))
    {
        best = b;
        bestchoice = 'b';
    }
    cout<<bestchoice<<" , "<<best<<endl;


    return 0;
}
