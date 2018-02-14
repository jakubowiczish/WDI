#include <iostream>
/* Dana jest tablica int t[N][N] zawieraj¹ca liczby naturalne. Dok³adnie w jednym z wierszy
tablicy znajduje siê fragment ci¹gu Fibonacciego o d³ugoœciwiêkszej ni¿2,a mniejszej ni¿ N. Proszê
napisaæ funkcjê, która odszuka ten fragment ci¹gu i zwróci numer wiersza w którym on siê znajduje.
Uwagi:
o Czas na rozwi¹zanie zadania wynosi 25 minut, za zadanie mo¿na otrzymaæ 5 punktów.
o oceniane bêd¹: przejrzystoœæ iczytelnoœæ kodu oraz efektywnoœæ rozwi¹zania'
*/
using namespace std;

bool isFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i) return true;
    }
    return false;
}

int nextFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i)
            return Fibonacci1 + Fibonacci2;
    }
    return -1;
}
int main()
{
    const int N = 10;
    int t[N][N];
    // testy przykladowe
    t[0][0] = 2;
    t[0][1] = 3;
    t[0][2] = 5;
    t[1][0] = 2;
    t[1][1] = 3;
    t[1][2] = 5;
    for(int i=0; i<N; i++)
    {
        int licznik = 0;
        int licznikMAX = 0;
        for(int j=0; j<N; j++)
        {
            if(isFibonacci(t[i][j]))
            {
                licznik++;
                if(licznik > licznikMAX)
                    licznikMAX = licznik;
            }
            else
                licznik = 0;
        }
    cout<<"ilosc liczb ciagu w wierszu " << i << " to "<< licznikMAX <<endl;
    }
return 0;
}
