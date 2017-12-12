#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica typu tab = array [1..100] of integer wype³niona liczbami naturalnymi.
Stoj¹c na polu tablicy o indeksie n mo¿emy przesun¹æ siê w prawo o liczbê bêd¹c¹
czynnikiem pierwszym liczby t[n]. Na przyk³ad:
- wartoœæ w polu tablicy wynosi 12, mo¿emy przeskoczyæ o 2 lub 3 pola,
- wartoœæ w polu tablicy wynosi 14, mo¿emy przeskoczyæ o 2 lub 7 pól,
- wartoœæ w polu tablicy wynosi 17, mo¿emy przeskoczyæ o 17 pól.
Proszê napisaæ program, który tablicê typu tab wype³nia liczbami pseudolosowymi z zakresu
[2..100], nastêpnie odpowiada na pytanie: czy jest mo¿liwe przejœcie z pola 1 do 100?
*/
using namespace std;
const int N = 30;
bool isPossible(int tab[N], int i);

int main()
{
    srand(time(NULL));
    int tab[N];
    for(int i=0; i < N; i++){
        tab[i] = rand()% 5000 + 2;
        cout << tab[i] << " ";
    }
    cout << endl << isPossible(tab,0) << endl;
    return 0;
}

bool isPossible(int tab[N], int i)
{
    if(i == N-1)
        return true;
    int a = tab[i];
    for(int p=2; p < a; p++){
        if(a%p == 0){
            while(a%p == 0){
                a /= p;
            }
            if(i+p < N){
                if(isPossible(tab,i+p)) return true;
            }
        }
    }
    return false;
}
