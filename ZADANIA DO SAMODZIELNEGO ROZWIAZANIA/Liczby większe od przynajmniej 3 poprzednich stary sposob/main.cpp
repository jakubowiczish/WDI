#include <iostream>
/*
Proszê napisaæ program czytaj¹cy z wejœcia liczby typu integer i wypisuj¹cy na wyjœciu te z nich,
które s¹ wiêksze od przynajmniej trzech poprzednich. Proszê rozwa¿yæ przypadki dla ci¹gu
wejœciowego o dowolnej d³ugoœci.
*/

using namespace std;

int main()
{
    int liczba;
    cin>>liczba;
    int tab[4];
    tab[0] = liczba;
    while(true)
    {
        cin>>liczba;
        if(liczba == 0)
            break;

        tab[3] = tab[2];
        tab[2] = tab[1];
        tab[1] = tab[0];

        tab[0] = liczba;

        if(tab[0] > tab[1] && tab[0] > tab[2] && tab[0] > tab[3])
            cout<<tab[0]<<" ";


    }
    return 0;
}
