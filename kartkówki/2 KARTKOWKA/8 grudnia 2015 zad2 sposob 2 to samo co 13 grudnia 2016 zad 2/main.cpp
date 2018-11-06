#include <iostream>
#include <cstdlib>
#include <ctime>
/*
2) Dana jest tablica t[N][N] (reprezentuj¹ca szachownicê) wype³niona liczbami ca³kowitymi z zakresu -9 ..9. Proszê napisaæ funkcjê.która
ustawia na szachownicy dwie wiee, tak aby suma liczb na szachowanych polach by³a najwiêksza. Do funkcji nale¿y przekazaæ tablicê, funkcja
powinna zwróciæ po³o¿enie wie¿'
Uwaga:
r Zak³adamy, ¿e pole na którym stoi wie¿a jest przez ni¹ szachowane.
. czas na rozwi¹zanie zadañ wynosi 40 min.
r za ka¿de zadanie mo¿na otrzymaæ maksymalnie 5 pkt.
. oceniane bêd¹: czytelnoœæ, poprawnoœæ i efektywnoœæ rozwi¹zañ
*/

using namespace std;
const int N = 4;

int main()
{
    int tab[N][N];

    int Max1 = 0;

    srand(time(NULL));
    //wyswietlanie tablicy
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<'\t';
        }
        cout<<endl<<endl;
    }
    int X1 = 0, Y1 = 0;
    int X2 = 0, Y2 = 0;

    int col_sum[N];
    int row_sum[N];
    for(int i=0; i<N; i++)
    {
        col_sum[i] = 0;
        row_sum[i] = 0;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            col_sum[i] += tab[j][i];
            row_sum[i] += tab[i][j];
        }
    }


    for(int x1=0; x1<N; x1++)
    {
        for(int y1=0; y1<N; y1++)
        {
            for(int x2=0; x2<N; x2++)
            {
                for(int y2=0; y2<N; y2++)
                {
                    if(x1 != x2 && y1 != y2)
                    {
                        int sum = col_sum[y1] + row_sum[x1] + col_sum[y2] + row_sum[x2];
                        if(sum > Max1)
                        {
                            Max1 = sum;
                            X1 = x1;
                            Y1 = y1;
                            X2 = x2;
                            Y2 = y2;
                        }
                    }
                }
            }
        }
    }

    cout<<"x1: "<<X1<<" y1: "<<Y1<<endl;
    cout<<"x2: "<<X2<<" y2: "<<Y2<<endl;
    return 0;
}
