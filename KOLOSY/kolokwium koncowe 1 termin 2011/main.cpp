#include <iostream>
#include <cstdlib>
#include <ctime>
/*Mamy tablicê [1..max,1..max]. Napisz funkcjê, która zwraca d³ugoœæ najd³u¿szego podci¹gu rosn¹cego
znajduj¹cego siê w dowolnym (jednym) wierszu, którego wszystkie elementy s¹ ze sob¹ wzglêdnie
pierwsze. */

using namespace std;
const int N = 5;
int LCD (int a, int b) //largest common divisor
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

int rowlength(int t[N][N]) // sprawdza czy wszystkie liczby w danym wierszu sa wzglednie pierwsze wobec siebie, jesli tak
{
    // to zapisuje wynik (flag)
    int counter = 1;
    int flag = 0;
    int pary = (N*(N-1))/2;
    int wynik;
    for(int i=0; i<N; i++)
    {
        int szukanadlugosc = 0;
        counter = 0;
        for(int j=0; j<N-1; j++)
        {
            for(int k=j+1; k<N; k++)
            {

                cout << "Wiersz: " << i << " iterator1: " << j << " iterator2: " << k << " wartosc1: " << t[i][j]
                << " wartosc2: " << t[i][k] << " wynik: " << LCD(t[i][j],t[i][k]) << endl;

                if( LCD(t[i][j],t[i][k]) == 1)
                {
                    counter++;
                    if(counter == N)
                    {
                        flag++;
                    }
                }
            }

            if(counter == pary)
            {
                if(t[i][j+1] > t[i][j])
                {
                    szukanadlugosc++;
                    wynik = szukanadlugosc;
                }
            }
        }
        cout<<endl;
        cout<<"dla wiersza: "<<i<<" wynik to : "<<counter<<endl;
        cout<<endl;
        counter = 1;
    }
    cout<<"szukana dlugosc to: "<<wynik<<endl;
    return flag;
}

int main()
{
    srand(time(NULL));
    int t[N][N];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            t[i][j] = rand() % 8 + 1;
        }
    }
    printtable(t);
    cout<<rowlength(t)<<endl;
    return 0;
}
