#include <iostream>
#include <cmath>
#include <limits.h>
/*
2. Mamy dany zbiór punktów.
type
punkt=record
x:integer;
y:integer;
end;
tab=array[1..max] of punkt;
Napisz funkcjê, która zwróci najmniejsz¹ odleg³oœæ miêdzy œrodkami ciê¿koœci 2 niepustych podzbiorów
tego zbioru.
*/
using namespace std;
const int N = 3;
struct Point
{
    double x,y;
};

void znajdz(Point tab[N], Point p1, int p1_size, Point p2, int p2_size, int i, int &min_odleglosc);
double odleglosc(Point p, Point r);
double zadanie(Point tab[N]);

int main()
{
    Point p1, p2, p3;

    // Testowanie.
    p1.x = 4.0;
    p1.y = 4.0;
    p2.x = 3.0;
    p2.y = 3.0;
    p3.x = 0.0;
    p3.y = 0.0;
    Point tab[] = { p1, p2, p3 };
    cout << zadanie(tab) << endl;

    return 0;
}

double odleglosc(Point p, Point r)
{
    return sqrt(
               fabs(p.x-r.x)*fabs(p.x-r.x)
            +  fabs(p.y-r.y)*fabs(p.y-r.y)
           );
}
double zadanie(Point tab[N])
{
    int min_odleglosc = INT_MAX;
    Point p;
    p.x = p.y = 0;
    znajdz(tab,p,0,p,0,0,min_odleglosc);
    return min_odleglosc;
}
void znajdz(Point tab[N], Point p1, int p1_size, Point p2, int p2_size, int i, int &min_odleglosc)
{
    double nowa_odleglosc = odleglosc(p1,p2);
    if(p1_size != 0 && p2_size != 0 && nowa_odleglosc < min_odleglosc){
        min_odleglosc = nowa_odleglosc;
    }
    if(i == N)
        return;
    Point p;

    if(p1_size != 0){
        p.x = (p1.x + tab[i].x)/2;
        p.y = (p1.y + tab[i].y)/2;
    }
    else{
        p = tab[i];
    }

    znajdz(tab,p, p1_size + 1, p2,p2_size, i+1 , min_odleglosc);

    if(p2_size != 0){
        p.x = (p2.x + tab[i].x)/2;
        p.y = (p2.y + tab[i].y)/2;
    }
    else{
        p = tab[i];
    }

    znajdz(tab,p1,p1_size,p, p2_size+1, i+1, min_odleglosc);
    znajdz(tab,p1,p1_size,p2,p2_size,i+1, min_odleglosc);
}
