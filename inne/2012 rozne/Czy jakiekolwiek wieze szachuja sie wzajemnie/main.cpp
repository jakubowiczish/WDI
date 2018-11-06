#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dany jest typ szachownica=array[1..8,1..8] of integer. Stoj¹ce na
szachownicy figury oznaczone s¹ liczbami ca³kowitymi np. bia³a wie¿a to 5,
a czarna –5, itd. Proszê napisaæ funkcjê, która sprawdza czy jakiekolwiek
wie¿e szachuj¹ siê wzajemnie
*/
using namespace std;
const int N = 5;
void set_table(int tab[N][N]);
bool AreChecking(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    cout << AreChecking(tab) << endl;
    return 0;
}

bool AreChecking(int tab[N][N]) /// true gdy jakies sie szachuja, w tablicy 1 gdy jest wieza, 0 gdy pole jest puste
{
    int w[N], k[N];
    for(int i=0; i < N; i++){
        w[i] = 0;
        k[i] = 0;
    }
    int index = 0;
    for(int i=0; i < N ; i++)
    {
        for(int j=0; j < N; j++)
        {
            if(tab[i][j] == 1){
                w[i]++;
                k[i]++;
            }
        }
    }

    for(int i=0; i < N; i++)
    {
        if(w[i] >= 2 or k[i] >= 2){
            return true;
        }
    }
    return false;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 2;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
