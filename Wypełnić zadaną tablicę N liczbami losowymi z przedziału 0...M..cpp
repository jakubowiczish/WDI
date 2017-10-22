#include <iostream>
#include <ctime>
#include <cstdlib>
// Wype³niæ zadan¹ tablicê N liczbami losowymi z przedzia³u 0...M.
using namespace std;

int main()
{
    const int N = 100;
    int M;
    cin>>M;
    int tab[N];
    for(int i=0; i<N; i++)
    {
        tab[i] = rand() % M;
        cout<<tab[i]<<" ";
    }
    return 0;
}
