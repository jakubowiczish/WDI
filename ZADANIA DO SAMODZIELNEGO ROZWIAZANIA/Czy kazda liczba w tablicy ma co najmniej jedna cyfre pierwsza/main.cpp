#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 2;


void setTable(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            tab[i][j] = rand() % 500 + 100;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

int main()
{
    int tab[N][N];
    setTable(tab); // ustawianie wartosci w tablicy i jej wyswietlanie

    int counter = 0; // zliczanie ile jest liczb w tablicy ktore maja co najmniej jedna cyfre pierwsza

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int next = tab[i][j]; // zmienna tymczasowa zeby sprawdzac cyfry

            bool result = false; // flaga okreslajaca czy w liczbie jest cyfra pierwsza, false - nie ma

            while(next > 0)
            {
                if (next % 10 == 2 || next % 10 == 3 || next % 10 == 5 || next % 10 == 7)
                {
                    result = true;
                }
                next /= 10;
            }

            if(result)
                counter++;
        }
    }

    if(counter == N*N)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;


    return 0;
}
