#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica t : array[ 1..w, 1..k ] of integer; wype³niona liczbami
naturalnymi. Proszê napisaæ fragment programu, który sprawdza czy
w ka¿dym wierszu i ka¿dej kolumnie wystêpuje przynajmniej jedna liczba
podzielna przez 23.
*/
using namespace std;
const int N = 3;
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);
bool checkTable(int tab[N][N]);

int main()
{
    int tab[N][N] =
    {
        {1,46,2},
        {69,24,4},
        {55,33,23}
    };
    print_table(tab);
    cout << checkTable(tab) << endl;
    return 0;
}

bool checkTable(int tab[N][N])
{
    int tabK[N], tabW[N];
    for(int i=0; i < N; i++){ /// inicjalizacja tablic pomocniczych
        tabK[i] = 0;
        tabW[i] = 0;
    }
    for(int i=0; i < N; i++) /// sprawdzanie kazdej komorki
    {
        for(int j=0; j < N; j++)
        {
            if(tab[i][j]%23 == 0){
                tabW[i]++;
                tabK[i]++;
            }
        }
    }
    int counterW = 0;
    int counterK = 0;
    for(int i=0; i < N; i++){
        if(tabW[i] >= 1){
            counterW++;
        }
        if(tabK[i] >= 1){
            counterK++;
        }
        if(counterW == N and counterK == N){
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
            tab[i][j] = rand()%23 + 23;
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

