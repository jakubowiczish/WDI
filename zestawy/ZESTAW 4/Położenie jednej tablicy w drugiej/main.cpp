
#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dwie liczby naturalne s¹ zgodne je¿eli w zapisie dwójkowym zawieraj¹ tê sam¹ liczbê jedynek,
np. 22 = 101102 i 14 = 11102. Dane s¹ tablice (MAX2>MAX1): int tab1[MAX1][MAX1]; int tab2[MAX2][MAX2];
Proszê napisad funkcjê, która sprawdza czy istnieje takie po³o¿enie tablicy typu tab1 wewn¹trz tablicy typu tab2,
przy którym liczba zgodnych elementów jest wiêksza od 33%.
Do funkcji nale¿y przekazad tablicê typu tab1 i tablicê typu tab2.
Obie oryginalne tablice powinny pozostad nie zmieniane.
*/
using namespace std;
const int N = 5;
const int M = 6;

void set_table(int tab[N][N]);
void set_table2(int tab[M][M]);
bool checkResemblance(int tab1[N][N], int tab2[M][M]);
bool areCompatible(int a, int b);

int main()
{
    int tab1[N][N];
    int tab2[M][M];
    cout << "First Table: " << endl << endl;
    set_table(tab1);
    cout << "Second Table: " << endl << endl;
    set_table2(tab2);

    cout << checkResemblance(tab1,tab2);
    return 0;
}

bool checkResemblance(int tab1[N][N], int tab2[M][M])
{
    int limit = N*N /3;
    int counter = 0;
    int finalCounter = 0;
    for(int i=0; i < M; i++)
    {
        for(int j=0; j < M; j++)
        {
            if(areCompatible(tab1[i][j],tab2[i][j]))
            {
                int maxAllowedSize = min(M - i, M - j);
                for(int k=0; k <= maxAllowedSize; k++)
                {
                    for(int m=0; m <= maxAllowedSize; m++)
                    {
                        if(areCompatible(tab2[i][j],tab1[k][m]))
                        {
                            counter++;
                            finalCounter = max(counter,finalCounter);
                        }
                    }
                }
            }
        }
    }
    if(finalCounter > limit)
        return true;
    return false;
}

bool areCompatible(int a, int b) /// robie dla dziesietnego na potrzeby zadania
{
    int counterA = 0;
    int counterB = 0;
    while(a > 0){
        if(a%10 == 1){
            counterA++;
        }
        a /= 10;
    }
    while(b > 0){
        if(b%10 == 1){
            counterB++;
        }
        b /= 10;

    }
    if(counterA == counterB)
        return true;
    return false;
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

void set_table2(int tab[M][M])
{
    srand(time(NULL));
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

