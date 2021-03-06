#include <iostream>
/*
Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem A(n)=n*n+n+1.
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
