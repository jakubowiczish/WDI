#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica wype³niona liczbami naturalnymi:
const int N=1000; int t[N][N];
Proszê napisaæ funkcjê, która poszukuje w tablicy kwadratu o liczbie pól bêd¹cej liczb¹ nieparzyst¹
wiêksz¹ od 1, którego iloczyn 4 pól naro¿nych wynosi k. Do funkcji nale¿y przekazaæ tablicê i wartoœæ
k. Funkcja powinna zwróciæ informacje czy uda³o siê znaleŸæ kwadrat oraz wspó³rzêdne (wiersz,
kolumna) œrodka kwadratu.
*/
using namespace std;
const int N = 5;
void print_table(int tab[N][N]);
void set_table(int tab[N][N]);
void findMachingCorners(int t[N][N], int k, /*out*/ int& row, /*out*/ int& col);

int main()
{
    int tab[N][N];
    set_table(tab);
    int k;
    cout << "Podaj k: " << endl;
    cin >> k;
    int row =0, col = 0;
    findMachingCorners(tab,k,row,col);
    cout << "Row: " << row <<  endl;
    cout << "Col: " << col << endl;
    return 0;
}

void findMachingCorners(int t[N][N], int k, /*out*/ int& row, /*out*/ int& col)
{
    for (int y1 = 0; y1 < N; y1++)
    {
        for (int x1 = 0; x1 < N; x1++)
        {
            if (k % t[y1][x1] == 0)
            {
                int maxAllowedSize = std::min(N - x1, N - y1);
                for (int size = 3; size <= maxAllowedSize; size += 2)
                {
                    int x2 = x1 + size - 1;
                    int y2 = y1 + size - 1;
                    if (t[y1][x1] * t[y1][x2] * t[y2][x1] * t[y2][x2] == k)
                    {
                        row = (y1 + y2) / 2;
                        col = (x1 + x2) / 2;
                        return;
                    }
                }
            }
        }
    }
    row = -1;
    col = -1;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 10 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void print_table(int tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

