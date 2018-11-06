#include <iostream>
/*
1. Dana jest tablica wype³niona liczbami naturalnymi:
const int N=1000;
int t[N][N];
Proszê napisaæ funkcjê, która w poszukuje w tablicy najd³u¿szego ci¹gu geometrycznego le¿¹cego ukoœnie w kierunku
prawo-dó³, licz¹cego co najmniej 3 elementy. Do funkcji nale¿y przekazaæ tablicê. Funkcja powinna zwróciæ
informacje czy uda³o siê znaleŸæ taki ci¹g oraz d³ugoœæ tego ci¹gu.
*/
using namespace std;
const int N = 4;

int findLongestGeometricSequence(int tab[N][N]);
int longestGeometricSequence(int tab[N][N], int w, int k);
void printTable(int tab[N][N]);

int main()
{
    int tab[N][N] = {
        {1,1,1,1},
        {1,2,3,4},
        {1,5,4,1},
        {1,2,4,8}
    };
    printTable(tab);
    cout << findLongestGeometricSequence(tab);
    return 0;
}

int findLongestGeometricSequence(int tab[N][N])
{
    int finalResult = 0;
    int actualResult = 0;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            actualResult = longestGeometricSequence(tab,i,j);
            //cout << actualResult << endl;
            if(actualResult > finalResult){
                finalResult = actualResult;
            }
        }
    }
    return finalResult;
}

int longestGeometricSequence(int tab[N][N], int w, int k)
{
    int distance_to_right_border = N - k - 1;
    int distance_to_bottom_border = N - w - 1;
    int distance_to_bottom_right_border = min(distance_to_right_border,distance_to_bottom_border);

    int actualLength = 1;
    int MaxLength = 0;
    bool found = false;
    for(int i=0; i <= distance_to_bottom_right_border - 2; i++)
    {
        int a1 = tab[w+i][k+i];
        int a2 = tab[w+i+1][k+i+1];
        int a3 = tab[w+i+2][k+i+2];
        if(a1*a3 == a2*a2){
            if (!found) {
                actualLength = 3;
                found = true;
            } else {
                actualLength++;
            }
        }
        else{
            if(actualLength > MaxLength){
                MaxLength = actualLength;
                actualLength = 1;
                found = false;
            }
        }
    }

    if(actualLength > MaxLength){
        MaxLength = actualLength;
    }

    return MaxLength;
}

void printTable(int tab[N][N])
{
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
