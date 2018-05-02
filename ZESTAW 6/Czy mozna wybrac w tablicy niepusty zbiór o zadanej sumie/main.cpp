#include <iostream>
/*
Tablica int t*8+*8+ zawiera liczby naturalne. Proszê napisad funkcjê, która sprawdza czy mo¿na
wybrad z tablicy niepusty podzbiór o zadanej sumie. Warunkiem dodatkowym jest aby ¿adne
dwa wybrane elementy nie le¿a³y w tej samej kolumnie ani wierszu. Do funkcji nale¿y
przekazad wy³¹cznie tablicê oraz wartoœd sumy, funkcja powinna zwrócid wartoœd typu bool.
*/
using namespace std;
int T[8][8]={
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8}};

bool suma_pomocnicza(int T[8][8], int suma_docelowa, int suma_aktualna, int aktualna_kolumna, bool zajete_wiersze[8]){
    if(aktualna_kolumna >= 8) return false;
    if(suma_aktualna == suma_docelowa) return true;

    if(suma_pomocnicza(T,suma_docelowa,suma_aktualna, aktualna_kolumna+1, zajete_wiersze)) return true;
    for(int i = 0; i < 8; i++){
        if(!zajete_wiersze[i]){
            zajete_wiersze[i]=true;
            if(suma_pomocnicza(T,suma_docelowa,suma_aktualna+T[aktualna_kolumna][i], aktualna_kolumna+1, zajete_wiersze)) return true;
            zajete_wiersze[i]=false;
        }
    }
    return false;
}

bool suma(int T[8][8], int suma_docelowa){
    bool zajete_wiersze[8];
    for(int i = 0; i < 8; i++) zajete_wiersze[i]=false;
    if(suma_pomocnicza(T,suma_docelowa,0, 0, zajete_wiersze)) return true;
    for(int i = 0; i < 8; i++){
        if(!zajete_wiersze[i]){
            zajete_wiersze[i]=true;
            if(suma_pomocnicza(T,suma_docelowa,T[0][i], 0, zajete_wiersze)) return true;
            zajete_wiersze[i]=false;
        }
    }
    return false;
}

int main() {
    cout << suma(T,36);
    return 0;
}
