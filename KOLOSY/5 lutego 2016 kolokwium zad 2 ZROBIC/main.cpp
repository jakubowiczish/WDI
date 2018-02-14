#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int counting(int n) // zliczanie ile liczba ma jedynek w systemie binarnym
{
    int next = n;
    int counter = 0;
    while(next > 0)
    {
        if(next%2 != 0)
        {
            counter++;
        }
        next /= 2;
    }
    return counter;
}

// *******************************************************8
int main()
{
    srand(time(NULL));
    const int N = 7;
    //int tab[N] = {2,3,5,7,11,13,16}; - przykladowe jak w zadaniu, sluzylo do sprawdzenia

    for(int i=0; i<N; i++)
    {
        //tab[i] = rand()% 100 + 1;
        cout<<tab[i]<<" ";
    }

    int sum = 0;

    cout<<endl<<endl;

    for(int i=0; i<N; i++)
    {
        sum += counting(tab[i]);
    }

    if(sum % 3 == 0)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;

    return 0;
}
