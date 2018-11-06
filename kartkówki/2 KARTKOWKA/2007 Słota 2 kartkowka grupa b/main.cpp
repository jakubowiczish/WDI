#include <iostream>
#include <ctime>
#include <cstdlib>
/*
 dana jest 2-wymiarowa tablica integer, znajdŸ element dla którego suma elementów le¿¹cych na
przek¹tnych na których przeciêciu znajduje siê nasz element jest najwiêksza
*/
using namespace std;
const int N = 3;

int podwojnaSumaUkosna(int tab[N][N], int x, int y); // funkcja liczaca sumy obu przekatnych ktore przecinaja sie w punkcie (x,y)
void set_table(int tab[N][N]); // inicjalizacja tablicy

int main()
{
    int tab[N][N];
    set_table(tab);

    int MaxSum = 0;
    int Sum = 0;
    int X = 0, Y = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int Sum = podwojnaSumaUkosna(tab,j,i);
            if(Sum > MaxSum)
            {
                MaxSum = Sum;
                X = i;
                Y = j;
                cout<<"suma: "<<Sum<<endl;
            }
        }
    }
    cout<<endl<<endl;
    cout<<"X: "<<X<<" Y: "<<Y<<endl;
    cout<<"MaxSum: "<<MaxSum<<endl;
    return 0;
}

int podwojnaSumaUkosna(int tab[N][N], int x, int y)
{
    int sum = 0;

    int distance_to_left_border = y;
    int distance_to_top_border = x;

    int steps_to_top_left_corner = min(distance_to_left_border,distance_to_top_border);
    for(int i=1; i <=steps_to_top_left_corner; i++)
    {
        sum += tab[x-i][y-i];
    }

    int distance_to_right_border = N - y - 1;
    int distance_to_bottom_border = N - x - 1;

    int steps_to_bottom_right_corner = min(distance_to_right_border,distance_to_bottom_border);
    for(int i=1; i <= steps_to_bottom_right_corner; i++)
    {
        sum += tab[x+i][y+i];
    }

    int steps_to_top_right_corner = min(distance_to_right_border,distance_to_top_border);
    for(int i=1; i <= steps_to_top_right_corner; i++)
    {
        sum += tab[x-i][y+i];
    }

    int steps_to_bottom_left_corner = min(distance_to_left_border,distance_to_bottom_border);
    for(int i=1; i <= steps_to_bottom_left_corner; i++)
    {
        sum += tab[x+i][y-i];
    }
    cout<<endl;
    cout<<"to bottom: "<<distance_to_bottom_border<<endl;
    cout<<"to top: "<<distance_to_top_border<<endl;
    cout<<"to left: "<<distance_to_left_border<<endl;
    cout<<"to right: "<<distance_to_right_border<<endl;

    return sum;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
