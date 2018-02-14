#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
/*
Dany jest typ:
type tab = array [1..max,1..max] of integer.
Proszê napisaæ procedurê która znajdzie w tablicy typu tab najwiêkszy kwadrat, z³o¿ony
wy³¹cznie z elementów, które w zapisie ósemkowym z³o¿one s¹ z niepowtarzaj¹cych siê cyfr.
Do procedury nale¿y przekazaæ tablicê i parametry znalezionego kwadratu (wspó³rzêdne
lewego górnego wierzcho³ka i d³ugoœæ boku). Kwadrat 1x1 te¿ jest kwadratem. W przypadku
nieznalezienia ¿adnego kwadratu d³ugoœæ boku = 0, dane wejœciowe w tablicy maj¹ zostaæ
niezniszczone.
*/
using namespace std;
const int N = 5;
bool notRepeated(int k);
void findSquare(int tab[N][N], int &left, int &up, int &a);
void print_table(int tab[N][N]);
void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    int left = 0, up = 0, a = 0;
    findSquare(tab,left,up,a);
    cout << "Left: " << left << endl;
    cout << "Up: " << up << endl;
    cout << "Side: " << a << endl;
    return 0;
}

void findSquare(int tab[N][N], int &left, int &up, int &a)
{
    int currentSide = 0; /// aktualny bok kwadratu
    int MaxSide = 0; /// maksymalny bok kwadratu
    bool found = false; /// czy znaleziono kwadrat
    for(int y1=0; y1 < N; y1++) /// lecimy po wspolrzednych
    {
        for(int x1=0; x1 < N; x1++)
        {
            if(notRepeated(tab[y1][x1])) /// lewy gorny corner kwadratu
            {
                found = false;
                int MaxAllowedSize = min(N - x1,N - y1); /// maksymalny wymiar kwadratu
                for(int size=1; size <= MaxAllowedSize; size++){
                    int x2 = x1 + size - 1;
                    int y2 = y1 + size - 1;

                    if(notRepeated(tab[y2][x2])){ /// prawy dolny corner kwadratu
                        int counter = 0;
                        for(int i=y1; i <= y2; i++) /// lecimy wewnatrz potencjalnego kwadratu
                        {
                            for(int j=x1; j <= x2; j++)
                            {
                                int supposedToBe = abs(y2-y1)*abs(x2-x1); /// tyle powinno byc liczb w kwadracie o niepowtarzajacych sie cyfrach
                                if(notRepeated(tab[i][j]))
                                {
                                    counter++;
                                    if(counter ==  supposedToBe){ /// jesli sie zgadza to szukamy MaxSide
                                        currentSide = counter;
                                        found = true;
                                    }
                                    if(currentSide > MaxSide){
                                        MaxSide = currentSide;
                                        up = y1;
                                        left = x1;
                                        a = MaxSide;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!found)
        a = 0;
}

bool notRepeated(int k) /// sprawdza czy w systemie osemkowym liczba sklada sie z niepowtarzajacych sie cyfr
{
    int tab[10];
    while(k > 0){
        tab[k%10]++;
        k /= 10;
    }
    for(int i=0; i < 10; i++){
        if(tab[i] > 1)
            return false;
    }
    return true;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 100 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void print_table(int tab[N][N])
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
