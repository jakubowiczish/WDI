#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dane s¹ dwie tablice mog¹ce pomieœciæ tak¹ sam¹ liczbê elementów:
 int t1[10][N];
 int t2[M]; // M = 10*N
W ka¿dym wierszu tablicy t1 znajduj¹ siê uporz¹dkowane rosn¹co (w obrêbie wiersza) liczby
naturalne.
Proszê napisaæ fragment programu przepisuj¹cy wszystkie singletony (liczby wystêpuj¹ce dok³adnie
raz) z tablicy t1 do t2, tak aby liczby w tablicy t2 by³y uporz¹dkowane rosn¹co. Pozosta³e elementy
tablicy t2 powinny zawieraæ zera.
*/
using namespace std;

int main()
{
    srand(time(NULL));
    const int N = 5;
    const int M = 10 * N;
    int tab1[10][N];
    int tab2[M];
    // wypelnienie tablicy
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab1[i][j] = rand () % 1000 + 1;
            cout<<tab1[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    int k = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab2[k++] = tab1[i][j];
        }
    }

    int tab3[10*N];
    int p = 0, r = 0;
    for(int i=0; i<10*N; i++)
    {
        for(int m=i+1; m<10*N-1; m++)
        {
            if(tab2[i] == tab2[m])
            {
                tab3[p++] = 0;
            }
            else
            {
                tab3[r++] = tab2[i];
            }
        }
    }

cout<<endl<<endl<<endl;
    for(int i=0; i<10*N; i++)
    {
        cout<<tab3[i]<<" ";
    }
    return 0;
}
