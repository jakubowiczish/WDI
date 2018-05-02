#include <iostream>
/*
Prosze napisac program czytajacy z wejscia liczby typu integer i wypisujacy na wyjsciu te z nich,
które sa mniejsze od przynajmniej trzech nastepnych. Prosze rozwazyc przypadki dla ciagu
wejsciowego o dowolnej d³ugosci.
*/
using namespace std;

int main()
{
    int a,b,c,d;
    int liczba;
    cin>>a>>b>>c>>d;

    while(liczba != 0)
    {
        if(a < b && a < c && a < d)
            cout<<a<<endl;

        cin>>liczba;

        //aktualizacja
        a = b;
        b = c;
        c = d;
        d = liczba;


    }
    return 0;
}
