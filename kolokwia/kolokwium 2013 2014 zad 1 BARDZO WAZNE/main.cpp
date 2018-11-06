#include <iostream>
/*
Tablica t[N][N] jest wype³niona liczbami naturalnymi. W dok³adnie jednym
wierszu istnieje dok³adnie jeden fragment ci¹gu Fibonacciego o d³ugoœci
wiêkszej ni¿ 2, mniejszej ni¿ N. Napisz funkcjê, która znajdzie ten fragment i
zwróci numer wiersza, w którym siê znajduje.
*/
using namespace std;
const int N = 3;
int row_of_Fibonacci(int tab[N][N]);
bool isFibonacci(int n);

int main()
{
    int tab[N][N] =
    {
        {5,13,34},
        {5,8,13},
        {1,3377,1}
    };
    cout << row_of_Fibonacci(tab);
    return 0;
}

int row_of_Fibonacci(int tab[N][N])
{
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N - 2; j++)
        {
            if(isFibonacci(tab[i][j]) and isFibonacci(tab[i][j+1]) and isFibonacci(tab[i][j+2]) and tab[i][j] + tab[i][j+1] == tab[i][j+2])
            {
                return i;
            }

        }
    }
    return -1;
}

bool isFibonacci(int n)
{
    int Fib1 = 0;
    int Fib2 = 1;
    while(Fib2 <= n)
    {
        int Fib3 = Fib1 + Fib2;
        Fib1 = Fib2;
        Fib2 = Fib3;
        if(Fib2 == n)
            return true;
    }
    return false;
}
