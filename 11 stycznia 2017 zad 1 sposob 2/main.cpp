#include <iostream>
using namespace std;
/*
Dwie liczby naturalne s¹ „przyjació³kami je¿eli zbiory cyfr z których zbudowane s¹ liczby s¹ identyczne.
Na przyk³ad: 123 i 321, 211 i 122, 35 3553. Dana jest tablica int t[MAX][MAX] wype³niona liczbami naturalnymi.
Proszê napisad funkcjê,
która dla tablicy t zwraca ile elementów tablicy s¹siaduje wy³¹cznie z przyjació³kami
*/
const int N = 3;
bool areFriends(int a, int b);
void print_table(int tab[N][N]);
int checkTabIfFriends(int tab[N][N]);
int counter_of_digits(int n);
bool isIndexValid(int a, int b);

int main()
{
    int tab[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>tab[i][j];
        }
    }
    cout<<endl;
    print_table(tab);
    cout<<checkTabIfFriends(tab);
    return 0;
}

bool isIndexValid(int a, int b)
{
    if(a >= 0 and b >= 0 and a < N and b < N)
        return true;
    return false;
}
int checkTabIfFriends(int tab[N][N])
{
    int d_x[] = {-1,0,1,-1,1,-1,0,1};
    int d_y[] = {-1,-1,-1,0,0,1,1,1};
    int counter = 0;

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            bool flag = true;
            for(int n_id=0; n_id < 8; n_id++) /// n_id = neighbour_id
            {
                if(isIndexValid(i + d_x[n_id],j + d_y[n_id]))
                {
                    if(!areFriends(tab[i][j],tab[i + d_x[n_id]][j + d_y[n_id]])){
                        flag = false;
                    }
                }
            }
            if(flag)
                counter++;
        }
    }
    return counter;
}

bool areFriends(int a, int b)
{
    int x = a;
    int y = b;

    int tab1[10];
    int tab2[10];

    for(int i=0; i < 10; i++)
        tab1[i] = 0;
    for(int i=0; i < 10; i++)
        tab2[i] = 0;

    while(x > 0){
        int ost = x%10;
        tab1[ost]++;
        x /= 10;
    }
    while(y > 0){
        int ost = y%10;
        tab2[ost]++;
        y /= 10;
    }
    for(int i=0; i < 10; i++){
        if((tab1[i] != 0 && tab2[i] == 0) || (tab2[i] == 0 && tab2[i] != 0))
            return false;
    }
    return true;

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
