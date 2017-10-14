#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int bigge
int main()
{
    const int max1 = 100, max2 = 200;
    int t[max1][max2];
    srand(time(NULL));
    for(int i=0; i<max1; i++)
    {
        for(int j=0; j<max2; j++)
        {
            t[i][j] = rand() % 100 + 1;
        }
    }

    return 0;
}
