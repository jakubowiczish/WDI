#include <iostream>
/*
1. Dana jest tablica wypełniona liczbami naturalnymi:
const int N=1000;
int t[N][N];
Proszę napisać funkcję, która w poszukuje w tablicy najdłuższego ciągu geometrycznego leżącego ukośnie w kierunku
prawo-dół, liczącego co najmniej 3 elementy. Do funkcji należy przekazać tablicę. Funkcja powinna zwrócić
informacje czy udało się znaleźć taki ciąg oraz długość tego ciągu.
*/
using namespace std;
const int N = 5;

int main()
{

    return 0;
}

int findInDiagonal(int tab[N][N], int x, int y)
{
    int maxLength = 0;
    int length = 0;

    while(y < N + 2 && x - 2 > 0)
    {
        long long a1 = tab[y][x];
        long long a2 = tab[y+1][x-1];
        long long a3 = tab[y+2][x-2];

        if(a2 * a2 == a1 * a3)
        {
            length++;
        }
        else
        {
            maxLength = max(maxLength,length);
            length = 2;
        }

        y++;
        x--;
    }

    maxLength = max(maxLength,length);

    return maxLength;
}

int FindLongestGeometricSequence(int tab[N][N])
{
    int maxLength = 0;
    for (int x = 2; x < N; x++)
    {
        maxLength = std::max(maxLength, findInDiagonal(tab, x, 0));
    }

    for (int y = 1; y < N - 2; y++)
    {
        maxLength = std::max(maxLength, findInDiagonal(tab, N - 1, y));
    }

    if (maxLength >= 3)
    {
        return maxLength;
    }

    else
    {
        return -1;
    }
}
