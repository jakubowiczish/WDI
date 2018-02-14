#include <iostream>
using namespace std;
/*
Dana jest tablica booli int t[N][N] reprezentująca szachownicę. Pole szachownicy ma
wartość true, jeżeli stoi na nim figura, a false, jeśli jest ono puste. Proszę napisać
funkcję która sprawdza czy istnieje droga skoczka przemieszczającego się z wiersza
0 do wiersza N-1. Skoczek może poruszać się tylko po polach pustych. Skoczek w
każdym ruchu powinien przybliżać się do N-1 wiersza. Funkcja ma zwrócić
najmniejszą możliwą liczbę ruchów. Skoczek może zacząć poruszać się z dowolnego
pustego pola z wiersza 0. N z zakresu 4...20.
*/
const int N = 9;
bool tab[N][N] =
{
    { false,false,true,false,false,true,true,false,true},
    { false,true,false,false,false,true,true,false,true},
    { false,true,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
};
int najKrok = -1;
bool mozliwe(int i, int w, int k, int &w1, int &k1)
{
    int dx[] = {2,1,-1,-2};
    int dy[] = {1,2,2,1};

    k1 = k + dx[i];
    w1 = w + dy[i];

    return ((k1 >= 0) and (k1 < N) and (w1 >=0) and (w1 < N) and tab[w1][k1] == false);
}

//wrzuca do globalnej zmiennej najKrok najmniejszą liczbę kroków do osiągnięcia wiersza N-1
void ilosc_krokow_do_celu(int n, int w, int k) // n - ilosc krokow, w - wiersz, k - kolumna
{
    if(w == N-1){
    	if(n<najKrok || najKrok == -1) najKrok = n;
    	return;

	}
    for(int i=0; i < 4; i++){
        int w1,k1;

        if(mozliwe(i,w,k,w1,k1)){
           ilosc_krokow_do_celu(n+1,w1,k1);
        }
    }
    return;
}



void print_table(bool tab[N][N])
{
    for(int i=0; i<N; i++) // wyswietlanie tablicy
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

int najszybsza_trasa(){
	int najNajKrok = -1;
    for(int i = 0; i < N; i++){
    	if(tab[0][i] == false){ //iteracja po każdym elemencie 1szego wiersza. Tyle jest mozliwosci startu skoczka
    		najKrok = -1; //reset globalnej zmiennej, do której wpisywana jest wartosc (czytaj opis ilosc_krokow_do_celu())
    		ilosc_krokow_do_celu(0,0,i);
    		cout << "KROKI KOLUMNA " << i << " : " << najKrok << endl;

    		if(najKrok!= -1 && (najKrok < najNajKrok || najNajKrok==-1)){
			//jeśli najKrok jest równe -1 to ilosc_krokow_do_celu nie znalazła ścieżki
			//jeśli najNajKrok jest równe -1 to jest to pierwsze sprawdzenie, więc należy wpisać cokolwiek pod najNajKrok (w kolejnych wpisaniach bedzie sprawdzane czy najKrok < najNajKrok)
    			najNajKrok = najKrok;
			}
		}
	}
	return najNajKrok;
}
int main()
{
    print_table(tab);
    cout << "KROKI NAJMNIEJ " << najszybsza_trasa() << endl;
    return 0;
}

