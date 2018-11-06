#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int N = 3;
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

void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);

    int sum_col[N];
    int sum_row[N];

    for(int i=0; i<N; i++)
    {
        sum_col[i] = 0;
        sum_row[i] = 0;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            sum_col[i] += tab[j][i];
            sum_row[i] += tab[i][j];

        }
    }

    int max_col = 0;
    int max_row = 0;
    int X = 0, Y = 0;

    for(int i=0; i<N; i++)
    {
        if(sum_col[i] > max_col)
        {
            max_col = sum_col[i];
            X = i;

        }
        if(sum_row[i] > max_row)
        {
            max_row = sum_row[i];
            Y = i;
        }
    }
    cout<<"X: "<<X<<" Y: "<<Y<<endl;
    return 0;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
