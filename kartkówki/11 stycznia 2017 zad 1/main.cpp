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

int checkTabIfFriends(int tab[N][N])
{
    int counter = 0;

    for(int x=0; x<N; x++)
    {
        for(int y=0; y<N; y++)
        {
            if(x > 0 && y > 0 && x < N-1 && y < N-1)
            {
                if(areFriends(tab[x][y],tab[x-1][y-1])
                   && areFriends(tab[x][y],tab[x-1][y])
                   && areFriends(tab[x][y],tab[x-1][y+1])
                   && areFriends(tab[x][y],tab[x][y-1])
                   && areFriends(tab[x][y],tab[x][y+1])
                   && areFriends(tab[x][y],tab[x+1][y])
                   && areFriends(tab[x][y],tab[x+1][y-1])
                   && areFriends(tab[x][y],tab[x+1][y+1]))
                    counter++;
            }
            else if(y == 0 && x != 0 && x != N-1)
            {
                if(areFriends(tab[x][0],tab[x-1][0])
                   && areFriends(tab[x][0],tab[x-1][1])
                   && areFriends(tab[x][0],tab[x][1])
                   && areFriends(tab[x][0],tab[x+1][0])
                   && areFriends(tab[x][0],tab[x+1][1]))
                    counter++;
            }
            else if(y == N-1 && x != 0 && x != N-1)
            {
                if(areFriends(tab[x][N-1],tab[x-1][N-1])
                   && areFriends(tab[x][N-1],tab[x-1][N-2])
                   && areFriends(tab[x][N-1],tab[x][N-2])
                   && areFriends(tab[x][N-1],tab[x+1][N-2])
                   && areFriends(tab[x][N-1],tab[x+1][N-1]))
                    counter++;
            }
            else if(x == 0 && y != 0 && y != N-1)
            {
                if(areFriends(tab[0][y],tab[0][y-1])
                   && areFriends(tab[0][y],tab[0][y+1])
                   && areFriends(tab[0][y],tab[1][y-1])
                   && areFriends(tab[0][y],tab[1][y])
                   && areFriends(tab[0][y],tab[1][y+1]))
                    counter++;
            }
            else if(x == N-1 && y != 0 && y != N-1)
            {
                if(areFriends(tab[N-1][y],tab[N-1][y-1])
                   && areFriends(tab[N-1][y],tab[N-1][y+1])
                   && areFriends(tab[N-1][y],tab[N-2][y-1])
                   && areFriends(tab[N-1][y],tab[N-2][y])
                   && areFriends(tab[N-1][y],tab[N-2][y+1]))
                    counter++;
            }
        }
    }

    if(areFriends(tab[0][0],tab[0][1])
       && areFriends(tab[0][0],tab[1][0])
       && areFriends(tab[0][0],tab[1][1]))
        counter++;

    if(areFriends(tab[N-1][N-1],tab[N-2][N-2])
       && areFriends(tab[N-1][N-1],tab[N-1][N-2])
       && areFriends(tab[N-1][N-1],tab[N-2][N-1]))
        counter++;
    if(areFriends(tab[0][N-1],tab[0][N-2])
       && areFriends(tab[0][N-1],tab[1][N-1])
       && areFriends(tab[0][N-1],tab[1][N-2]))
        counter++;
    if(areFriends(tab[N-1][0],tab[N-2][0])
       && areFriends(tab[N-1][0],tab[N-2][1])
       && areFriends(tab[N-1][0],tab[N-1][1]))
        counter++;

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
