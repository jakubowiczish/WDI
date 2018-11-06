#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Napisaæ program wype³niaj¹cy tablicê int t[MAX] liczbami naturalnymi 1-1000 i sprawdzaj¹cy
czy istnieje element tablicy zawieraj¹cy wy³¹cznie cyfry nieparzyste
*/

using namespace std;
const int N = 10;

int counter_of_digits(int n);
bool check_table(int tab[], int N);

int main()
{
    srand(time(NULL));
    int tab[N];
    cout<<endl;
    cout<<check_table(tab,N);
    return 0;
}

int counter_of_digits(int n)
{
    int next = n;
    int counter = 0;

    while(next > 0)
    {
        counter++;
        next /= 10;
    }
    return counter;
}

bool check_table(int tab[], int N)
{
    for(int i=0; i<N; i++)
    {
        tab[i] = rand() % 1000 + 1;
        cout<<tab[i]<<" ";
    }

    for(int i=0; i<N; i++)
    {
        int counter = 0;
        int next = tab[i];
        while(next > 0)
        {
            if((next%10)%2 != 0)
                counter++;

            if(counter_of_digits(tab[i]) == counter)
                return true;
            next /= 10;
        }
    }

    return false;
}
