#include <iostream>
using namespace std;
/*
Dana jest tablica wype³niona liczbami naturalnymi:
int t[MAX][MAX];
Proszê napisad funkcjê, która w poszukuje w tablicy najd³u¿szego ci¹gu geometrycznego le¿¹cego ukoœnie w
kierunku prawo-dó³, licz¹cego co najmniej 3 elementy. Do funkcji nale¿y przeka
*/
const int N = 3;
int geometric_sequence(int tab[N][N]);

int main()
{
    int tab[N][N] =
    {
        {1,2,3},
        {1,2,5},
        {1,6,4},
    };
    cout<<geometric_sequence(tab);
    return 0;
}

int geometric_sequence(int tab[N][N])
{
    double quotient = tab[1][1]/tab[0][0];
    int result = 0;
    for(int x=0; x<N-1; x++)
    {
        for(int y=0; y<N-1; y++)
        {
            int length = 1;
            int MaxLength = 1;
            int distance_to_bottom_border = N - x - 1;
            int distance_to_right_border = N - y - 1;
            int steps_to_bottom_right_corner = min(distance_to_bottom_border,distance_to_right_border);

            double temp = tab[x+1][y+1]/tab[x][y];
            for(int i=1; i<=steps_to_bottom_right_corner; i++)
            {
                if(temp == quotient)
                    length++;
                else
                {
                    if(length > MaxLength){
                        MaxLength = length;
                        result = MaxLength;
                    }
                    length = 1;
                }
                quotient = tab[x+i][y+i]/tab[x][y];
            }
        }
    }
    return result;
}
