#include <iostream>

using namespace std;

void dzielenie(int a, int b, int N) // a - licznik, b - mianownik, N - ilosc cyfr po przecinku
{
    int x = a; // x - zmienna tymczasowa zeby a nie uleglo zmianie

    if(a < b)
    {
        cout<<a/b<<'.';
        for(int i=0; i<N; i++)
        {
            a *= 10;
            cout<<a/b;
            a %= b;
        }
    a = x; // zeby powrocila stara wartosc a
    }

    if(a > b)
    {
        cout<<a/b<<'.';
        for(int i=0; i<N; i++)
        {
            a %= b;
            a *= 10;
            cout<<a/b;
        }
    a = x;
    }
    if(a == b)
    {
        cout<<a/b<<'.';
        for(int i=0; i<N; i++)
        {
            cout<<0;
        }
    }
}


int main()
{
    int L,M,D;
    cout<<"Podaj licznik: ";
    cin>>L;
    cout<<endl<<"Podaj mianownik: ";
    cin>>M;
    cout<<endl<<"Podaj ile cyfr po przecinku ma wyswietlic program: ";
    cin>>D;
    dzielenie(L,M,D);
    return 0;
}
