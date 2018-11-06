#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    const int N = 20;
    int tab1[N][N];
    int tab2[10*N];

    srand(time(NULL));
    for(int i=0;i<N; i++) // wypelnienie tablicy na wlasne potrzeby
    {
        for(int j=0; j<N; j++)
        {
            tab1[i][j] = rand() % 5 + 1;
            cout<<tab1[i][j]<<" ";
        }
    cout<<endl;
    }
    cout<<endl<<endl<<endl;

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N-1; j++)
        {
            for(int k=j+1; k < N; k++)
            {
                if(tab1[i][j] == tab1[i][k])
                {
                    tab2[i] = 0;
                }
                else
                {
                    tab2[i] = tab1[i][j];
                }
            }
        }
    }
    int licznik = 0;
    for(int i=0; i<10*N; i++)
    {
       licznik++;
       if(licznik > 5)
        cout<<endl;
       licznik = 0;
    cout<<tab2[i]<<" ";
    }
    return 0;
}
