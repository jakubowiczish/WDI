#include <iostream>
/*
Dane s¹ deklaracje:
const
max = 20;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Proszê napisaæ procedurê, która zmienn¹ typu tablica wype³nia "po spirali" kolejnymi
wyrazami ci¹gu arytmetycznego o zadanym wyrazie pocz¹tkowym i zadanej ró¿nicy ci¹gu. Do
procedury nale¿y przekazaæ: wype³nian¹ tablicê, wyraz pocz¹tkowy i ró¿nicê ci¹gu.
2 4 6 8 10
32 34 36 38 12
30 48 50 40 14
28 46 44 42 16
26 24 22 20 18
*/
using namespace std;
const int N = 10;

void fill_array(int tab[N][N], int a1, int r)
{
    int dlugosc = N-1;
    bool doPrzodu = true; // true w prawo i dol
    int i = 0, j = 0;
    for(int k=0; k<dlugosc; k++)
    {
        tab[i][j] = a1;
        a1 += r;
        doPrzodu ? j++ : j--;
    }

    for(; dlugosc > 0; dlugosc--)
    {
        for(int k=0; k<dlugosc; k++)
        {
            tab[i][j] = a1;
            a1 += r;
            doPrzodu ? i++ : i--;
        }

        doPrzodu = !doPrzodu; // zmiana na false, do gory i w lewo

        for(int k=0; k<dlugosc; k++)
        {
            tab[i][j] = a1;
            a1 += r;
            doPrzodu ? j++ : j--;
        }
    }
    tab[i][j] = a1; // ostatni element
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
    cout<<endl<<endl;
    }
}
int main()
{
    int t[N][N];
    int a1,r;
    fill_array(t,1,1);
    return 0;
}
