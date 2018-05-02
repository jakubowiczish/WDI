#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Napisad funkcjê która dla tablicy typu int t[MAX][MAX], wype³nionej liczbami ca³kowitymi, zwraca wartoœd true w przypadku,
gdy w ka¿dym wierszu i ka¿dej kolumnie wystêpuje co najmniej jedno 0 oraz wartoœd false w przeciwnym przypadku.
*/
using namespace std;
const int N = 3;
bool checkIfZeroExists(int tab[N][N]);
void set_table(int tab[N][N]);
void printTable(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    //printTable(tab);
    cout << checkIfZeroExists(tab);

    return 0;
}

bool checkIfZeroExists(int tab[N][N])
{
    int rows[N];
    int columns[N];
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            rows[i] = 0;
            columns[i] = 0;
        }
    }

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            int k = tab[i][j];
            if(k == 0){
                ++rows[i];
                ++columns[j];
            }

            while(k > 0)
            {
                if(k%10 == 0)
                {
                    ++rows[i];
                    ++columns[j];
                }
                k /= 10;
            }
        }
    }
    for(int i=0; i < N; i++){
        cout << "Row nr " << i <<" number of 0: " << rows[i] << endl;
        cout << "Column nr " << i <<" number of 0: " << columns[i] << endl;
    }
    for(int i=0; i < N; i++){
        if(rows[i] == 0 or columns[i] == 0)
            return false;
    }
    return true;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 2;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void printTable(int tab[N][N])
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
