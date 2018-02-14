#include <iostream>

using namespace std;

const int N = 10;
const int M = N*N;

void przepisz(int tab1[N][N], int tab2[N*N])
{
    for(int i=0; i<N*N; i++) // przepisywanie
    {
        int minimum = -1;

        for(int j=0; j<N; j++)
        {
            if(tab1[j][0] != -1)
            {
                if(minimum == -1 || tab1[j][0] < tab[minimum][0])
                    minumum = j;
            }
        }
    }
}
