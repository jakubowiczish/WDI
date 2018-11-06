#include <iostream>
#include <ctime>
#include <cstdlib>

//Czy hetmani dla danego ustawienia sie szachuja

using namespace std;
const int N = 5;
const int P = 2*N-1;

bool areHetmansChecking(int tab[N][N]);
void set_table(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    cout << areHetmansChecking(tab);

    return 0;
}

bool areHetmansChecking(int tab[N][N])/// true gdy sie szachuja
{
    int w[N], k[N];
    int slant1[P], slant2[P];
    for(int i=0; i < N; i++){
        w[i] = 0;
        k[i] = 0;
    }
    for(int i=0; i < P; i++){
        slant1[i] = 0;
        slant2[i] = 0;
    }

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            if(tab[i][j] == 1){
                w[i]++;
                k[i]++;
                slant1[abs(i-j)]++;
                slant2[abs(i+j)]++;
            }
        }
    }
    for(int i=0; i < N; i++){
        if(w[i] >= 2 || k[i] >= 2){
            return true;
        }
    }

    for(int j=0; j < P; j++){
        if(slant1[j] >= 2 || slant2[j] >= 2){
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
            tab[i][j] = rand()%2;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
