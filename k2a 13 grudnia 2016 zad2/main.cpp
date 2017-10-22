#include <iostream>
/*
Dana jest tablica t[N][N] (reprezentuj¹ca szachownicê) wype³niona liczbami naturalnymi.
Proszê napisaæ funkcjê która ustawia na szachownicy dwie wie¿e, tak aby suma liczb na
„szachowanych” przez wie¿e polach by³a najwiêksza. Do funkcji nale¿y przekazaæ tablicê,
funkcja powinna zwróciæ po³o¿enie wie¿.
Uwagi:
- zak³adamy, ¿e wie¿a szachuje ca³y wiersz i kolumnê z wy³¹czeniem pola na którym stoi
- czas na rozwi¹zanie obu zadañ wynosi 45 minut
- za ka¿de zadanie mo¿na otrzymaæ maksymalnie 5 pkt
- oceniane bêd¹: czytelnoœæ, poprawnoœæ i efektywnoœæ rozwi¹zañ
*/
using namespace std;
int main(int argc, char** argv)
{
    const int n = 3;
    int T[n][n];
    T[0][0]=1;
    T[0][1]=1;
    T[0][2]=1;
    T[1][0]=1;
    T[1][1]=1;
    T[1][2]=2;
    T[2][0]=1;
    T[2][1]=1;
    T[2][2]=1;
    T[3][0]=1;
    T[3][1]=1;
    T[3][2]=1;


    int sumaMax = 0;
    int sumaMax2 = 0;

    int wieza1X;
    int wieza1Y;
    int wieza2X;
    int wieza2Y;

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            cout << "[" << T[i][j]<<"]";
        }
        cout << endl;
    }

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            int suma = 0;
            for(int k = 0; k < n ; k++)
            {
                if(k!=i)  //ten sam wiersz
                {
                    suma+=T[k][j];

                }
            }
            for(int k = 0; k < n ; k++)
            {
                if(k!=i)  //ta sama kolumna
                {
                    suma+=T[i][k];
                }
            }
            if(suma>=sumaMax2)
            {
                wieza2X = wieza1X;
                wieza2Y = wieza1Y;
                wieza1X = i;
                wieza1Y = j;

                sumaMax = sumaMax2;
                sumaMax2 = suma;
            }
            cout << "Na pozycji " << i << "," << j << " mamy sume szachowan " << suma << endl;

        }
    }
    cout << "Najwieksze sumy " << sumaMax << "," << sumaMax2 << endl;
    cout << "Postaw wieze1 na  " << wieza1X << "," << wieza1Y << endl;
    cout << "Postaw wieze2 na  " << wieza2X << "," << wieza2Y << endl;


    return 0;
}
