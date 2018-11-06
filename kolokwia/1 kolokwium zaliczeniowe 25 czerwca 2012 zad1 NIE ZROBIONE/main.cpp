#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int N = 11;

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}


int GCD(int a, int b)
{
    int c;
    while(b != 0)
    {
       c = a%b;
       a = b;
       b = c;
    }
    return a;
}

void printtable(int t[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<t[i][j]<<" ";
        }
    cout<<endl;
    }
}

//************************************************* MAIN ************************************************

int main()
{
    int tab[N][N];
    int nowa[N*N];
    int nowa2[100];
    srand(time(NULL));

    for(int i=0; i<N; i++) // wypelnienie tablicy
    {
        for(int j=0; j<N; j++)
        {
           tab[i][j] = rand() % 50 + 1;
        }
    }
    printtable(tab);
    cout<<endl<<endl;
    int k = 0;

    for(int i=0; i<N; i++) // przepisanie do nowej tablicy
    {
        for(int j=0; j<N; j++)
        {
            nowa[k++] = tab[i][j];
        }
    }

    cout<<"Przed posortowaniem: "<<endl;
    for(int m=0; m<N*N; m++)
    {
        cout<<nowa[m]<<" ";
    }

    cout<<endl<<"sprawdzana wzglednosc: "<<endl;
    for(int m=0; m<N*N; m++)
    {
        for(int p=m+1; p<N*N; p++)
        {
            if(GCD(nowa[m],nowa[p]) == 1)
            {
                nowa2[m] = nowa[m];
            }
        }
    }
    cout<<endl<<"nowa2 przed posortowaniem"<<endl;
    for(int m=0; m<100; m++)
    {
        cout<<nowa2[m]<<" ";
    }
    cout<<endl;
    quicksort(nowa2,0,N*N);
    cout<<"Po posortowaniu: "<<endl;
    for(int m=0; m<100; m++)
    {
        cout<<nowa2[m]<<" ";
    }
    return 0;
}
