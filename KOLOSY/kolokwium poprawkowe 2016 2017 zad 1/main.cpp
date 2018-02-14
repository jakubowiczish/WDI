#include <iostream>
/*
Dana jest tablica int t[N][N] zawieraj¹ca liczby naturalne. Dok³adnie w jednym
wierszu, b¹dŸ kolumnie znajduje siê fragmentu ci¹gu arytmetycznego o d³ugoœci
wiêkszej ni¿ 2, którego elementy s¹ liczbami pierwszymi. Proszê napisaæ funkcjê
która zwróci d³ugoœæ tego ci¹gu.
*/
using namespace std;
const int N = 3;
bool isPrime(int n);
int FindArithmeticRow(int tab[N][N]);

int main()
{
    int tab[N][N] =
    {
        {5,4,4},
        {1,1,1},
        {3,7,11}
    };
    cout << "MaxLength: " << FindArithmeticRow(tab) << endl;

    return 0;
}

int FindArithmeticRow(int tab[N][N])
{
    int MaxLength = 0;
    for(int i=0; i < N; i++)
    {
        int diff = tab[i][1] - tab[i][0];
        int ActualLength = 1;
        for(int j=0; j < N-1; j++)
        {
            if(isPrime(tab[i][j]) and isPrime(tab[i][j+1]) and (tab[i][j] + diff) == tab[i][j+1]){
                ActualLength++;
            }
            else{
                diff = tab[i][j+1] - tab[i][j];
                ActualLength = 1;
            }
            MaxLength = max(MaxLength,ActualLength);
        }
    }
    if(MaxLength > 2) return MaxLength;
    else return -1;
}

bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
