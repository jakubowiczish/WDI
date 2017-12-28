#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Liczby naturalne a,b s¹ komplementarne je¿eli ich suma jest liczb¹ pierwsz¹.
ana jest tablica typu int t[MAX][MAX] wype³niona liczbami naturalnymi.
Proszê napisad funkcjê, która zeruje elementy nie posiadaj¹ce liczby komplementarnej.
*/
using namespace std;
const int N = 5;

bool isPrime(int n);
bool areComplementary(int a, int b);
void zeroTable(bool tab[N][N]);
void setTable(int tab[N][N]);
void printTable(int tab[N][N]);
void zeroThoseWithoutComplementary(int tab[N][N]);

int main()
{
    int tab[N][N];
    cout << "Original array: " << endl << endl;
    setTable(tab);
    zeroThoseWithoutComplementary(tab);
    cout << "Changed array: " << endl << endl;
    printTable(tab);
    return 0;
}

void zeroThoseWithoutComplementary(int tab[N][N])
{
    bool shouldBeZero[N][N];
    zeroTable(shouldBeZero);
    bool found = false;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            found = false;
            for(int k=0; k < N; k++)
            {
                for(int m=0; m < N; m++)
                {
                    if((i != k) and (j != m) and areComplementary(tab[i][j],tab[k][m])){
                        found = true;
                        shouldBeZero[k][m] = false;
                    }
                }
            }
            if(found)
                shouldBeZero[i][j] = false;
        }
    }

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            if(shouldBeZero[i][j])
                tab[i][j] = 0;
        }
    }
}

void zeroTable(bool tab[N][N])
{
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            tab[i][j] = true;
        }
    }
}

bool areComplementary(int a, int b)
{
    if(isPrime(a+b))
        return true;
    return false;
}

bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <=n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

void setTable(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            tab[i][j] = rand() % 473746 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
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
