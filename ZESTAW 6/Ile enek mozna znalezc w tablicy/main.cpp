#include <iostream>
/*
Mamy dan¹ liczbê ca³kowit¹. W tablicy jednowymiarowej nale¿y znaleŸd n liczb, których suma jest równa danej liczbie.
Proszê napisad funkcjê Nka, która otrzymuj¹c jako parametry
(1) tablicê int t[N],) n (iloœd liczb stanowi¹cych sumê) oraz sumê sprawdza, ile mo¿na w niej znaleŸd „enek”.
*/
using namespace std;
const int N = 10;
int T[N] = {1,2,3,4,5,6,7,8,9,10};

int znalezione_liczby=0;
void enka_pomocnicza(int T[N], int n, int ilosc_aktualnie, int suma_docelowa, int suma_aktualna){
    if(ilosc_aktualnie > n) return;
    if(suma_aktualna > suma_docelowa) return;
    if(ilosc_aktualnie == n && suma_docelowa==suma_aktualna){
        znalezione_liczby++;
        return;
    }

    for(int i = 0; i < N; i++){
        enka_pomocnicza(T,n,ilosc_aktualnie+1,suma_docelowa,suma_aktualna+T[i]);
    }
    return;
}
int enka(int T[N], int n, int suma){
    znalezione_liczby=0;
    enka_pomocnicza(T,n,0,suma,0);
    return znalezione_liczby;
}

int main() {
    cout << enka(T,2,7);
    return 0;
}
