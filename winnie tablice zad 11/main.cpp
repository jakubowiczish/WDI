#include <iostream>
/*
Dane s¹ nastêpuj¹ce definicje:
const
max = 10;
var
tab: array[1..max] of real;
Proszê napisaæ program, który wczytuje wprowadzony z klawiatury ci¹g dodatnich liczb
rzeczywistych zakoñczony wartoœci¹ -1, bêd¹c¹ znacznikiem koñca ci¹gu i umieszcza max
najwiêkszych elementów w tablicy tab. Mo¿na za³o¿yæ, ¿e ci¹g zawiera co najmniej max liczb.
*/
using namespace std;

int main()
{
    int nowe[10] = {0,0,0,0,0,0,0,0,0,0};
    int liczba;
    cin>>liczba;
    nowe[0] = liczba;
    while(liczba != 0)
    {
        cin>> liczba;
        while(liczba > nowe[0])
        {
            for(int i=9; i>=1; i--)
            {
                nowe[i] = nowe[i-1];
            }

            nowe[0] = liczba;
        }
    }
    for(int i=0; i<10; i++)
        cout<<nowe[i]<<" ";

    return 0;
}
