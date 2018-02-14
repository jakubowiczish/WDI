ni#include <iostream>
/*
Prosze napisac program, który wype³nia tablice int tab[MAX] trzycyfrowymi liczbami
pseudolosowymi, a nastepnie wyznacza i wypisuje d³ugosc najd³uzszego podciagu spójnego
znajdujacego sie w tablicy dla którego w tablicy wystepuje równiez rewers tego ciagu.
Na przyk³ad dla tablicy: 2,9,3,1,7,11,9,6,7,7,1,3,9,12,15 odpowiedzia jest liczba 4.
*/
using namespace std;
const int N = 7;

int main()
{
    int tab[N];
    tab[0] = 0;
    tab[1] = 1;
    tab[2] = 3;
    tab[3] = 5;
    tab[4] = 7;
    tab[5] = 1;
    tab[6] = 0;

    int result = 0;
    for(int start=0; start<N; start++)
    {
        for(int r_start=N-1; r_start>=0; r_start--)
        {
            int i = 0;
            while(start + i < N && r_start - i >= 0 && tab[start + i] == tab[r_start - i]){
                i++;
            }

            result = max(result,i);
        }
    }
    cout<<result<<endl;
    return 0;
}
