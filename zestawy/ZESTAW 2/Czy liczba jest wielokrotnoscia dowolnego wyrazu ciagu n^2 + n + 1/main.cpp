#include <iostream>
/*
Napisz program wczytuj¹cy liczbê naturaln¹ z klawiatury i odpowiadaj¹cy na pytanie,
czy liczba ta jest wielokrotnoœci¹ dowolnego wyrazu ci¹gu danego wzorem A(n)=n*n+n+1.
*/
using namespace std;

int main()
{
    int k;
    cin >> k;
    bool out = false;
    bool result = false;
    int n = 1;
    while(!out && !result)
    {
        if((n*n + n + 1) > k)
            out = true;
        if(k % (n*n + n + 1) == 0)
            result = true;
        else
            n++;
    }

    if(result)
        cout <<"Tak, liczba jest wielokrotnoscia jakiegos wyrazu ciagu: n*n + n + 1" << endl;
    else
        cout <<"Nie, liczba nie jest wielokrotnoscia jakiegos wyrazu ciagu: n*n + n + 1" << endl;

    return 0;
}
