#include <iostream>

using namespace std;
/*
Dany jest typ tablicowy mapa = array [ 1..max,1..max ] of Boolean;
reprezentuj¹cy mapê. Wartoœæ true oznacza l¹d, a wartoœæ false ocean. Na
oceanie znajduj¹ siê wyspy utworzone przez s¹siaduj¹ce pola (rysunek). Proszê
napisaæ w Pascalu funkcjê do której przekazujemy mapê i wspó³rzêdne x,y
punktu na mapie. Je¿eli wspó³rzêdne oznaczaj¹ punkt na wyspie, funkcja
powinna zatopiæ wyspê. Funkcja powinna zwróciæ rozmiar zatopionego obszaru.
Mo¿na za³o¿yæ, ¿e ¿adna wyspa na mapie nie styka siê z jej krawêdzi¹.
*/
const int N = 5;

int plunge(bool tab[N][N],int x, int y)
{
    if(!tab[x][y])
        return 0;
    tab[x][y] = false;

    return 1 + plunge(tab,x+1,y) + plunge(tab,x-1,y) + plunge(tab,x,y-1) + plunge(tab,x,y+1);
}

int main()
{
    bool tab[N][N] =
    {
        {false,false,false,false,false},
        {false,true,true,false,false},
        {false,false,true,true,false},
        {false,true,true,false,false},
        {false,false,false,false,false},
    };
    int a,b;
    cin >> a >> b;
    cout<<plunge(tab,a,b);

return 0;
}
