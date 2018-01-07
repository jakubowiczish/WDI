#include <iostream>
#include <cstdlib>
#include <ctime>
/*
 const
max = 10;
type
tablica = array[1..max, 1..max] of integer;
var
T: tablica;
Zak³adamy, ¿e zmienna typu tablica jest wype³niona przypadkowymi wartoœciami. Proszê
napisaæ procedurê, która dla zmiennej typu tablica zwraca wspó³rzêdne i, j elementu T[i, j]
dla którego suma elementów w "ukoœnych rzêdach" jest najwiêksza.
*/
using namespace std;
const int N = 3;

void set_table(int tab[N][N]);
int DiagonalSum(int tab[N][N], int w, int k);
void findTheElement(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    findTheElement(tab);

    return 0;
}

int DiagonalSum(int tab[N][N], int w, int k)
{
    int distance_to_left_border = k;
    int distance_to_top_border = w;

    int distance_to_right_border = N - k - 1;
    int distance_to_bottom_border = N - w - 1;

    int distance_to_top_left_border = min(distance_to_left_border,distance_to_top_border);
    int distance_to_top_right_border = min(distance_to_right_border,distance_to_top_border);
    int distance_to_bottom_left_border = min(distance_to_left_border,distance_to_bottom_border);
    int distance_to_bottom_right_border = min(distance_to_right_border,distance_to_bottom_border);

    int sum = 0;

    for(int i=0; i <= distance_to_top_left_border; i++){
        sum += tab[w-i][k-i];
    }

    for(int i=0; i <= distance_to_top_right_border; i++){
        sum += tab[w-i][k+i];
    }

    for(int i=0; i <= distance_to_bottom_left_border; i++){
        sum += tab[w+i][k-i];
    }
    for(int i=0; i <= distance_to_bottom_right_border; i++){
        sum += tab[w+i][k+i];
    }
    return sum;
}

void findTheElement(int tab[N][N])
{
    int ActualSum = 0;
    int MaxSum = 0;

    int X,Y;

    for(int w=0; w < N; w++)
    {
        for(int k=0; k < N; k++)
        {
            ActualSum = DiagonalSum(tab,w,k);
            if(ActualSum > MaxSum)
            {
                MaxSum = ActualSum;
                X = k;
                Y = w;
            }
        }
    }
    cout << "Wiersz: " << Y << endl;
    cout << "Kolumna: " << X << endl;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
