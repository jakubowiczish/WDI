#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
Zad. 1 Dana jest du¿a tablica typu tab=array [1..max, 1..max] of integer wype³niona liczbami
naturalnymi. Proszê napisaæ funkcjê, która sprawdza czy w tablicy istniej¹ dwa elementy odleg³e o
jeden ruch skoczka szachowego, których wartoœci s¹ liczbami wzglêdnie pierwszymi.
Uwagi:
• Zawartoœæ tablicy wejœciowej nie mo¿e ulec zmianie.
• Czas na rozwi¹zanie zadania wynosi 25 minut, za zadanie mo¿na otrzymaæ 5 punktów.
• Oceniane bêd¹: przejrzystoœæ i czytelnoœæ kodu oraz efektywnoœæ rozwi¹zania.
*/
const int N = 3;
int GCD(int a, int b);
bool ableToJump(int i, int w, int k, int &w1, int &k1);
bool ifPossible(int tab[N][N]);
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);


int main()
{
    int tab[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cin >> tab[i][j];
    }
    cout << ifPossible(tab) << endl;
    return 0;
}

bool ifPossible(int tab[N][N])
{
    int number_of_possible_moves = 8;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            int w1,k1;
            for(int m=0; m<number_of_possible_moves; m++)
            {
                if(ableToJump(m,i,j,w1,k1))
                {
                    if(GCD(tab[i][j],tab[w1][k1]) == 1)
                        return true;
                }
            }
        }
    }
    return false;
}

bool ableToJump(int i, int w, int k, int &w1, int &k1)
{
    int dx[] = {1,2,2,1,-1,-2,-2,-1};
    int dy[] = {-2,-1,1,2,2,1,-1,-2};

    k1 = k + dx[i];
    w1 = w + dy[i];

    return ((k >= 0) && (k1 < N) && (w1 >= 0) && (w1 < N));
}

int GCD(int a, int b)
{
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 10 + 20;
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

