#include <iostream>
/*
Napisać procedurę, która dla danego zbioru znaków wypisuje
wszystkie jego podzbiory zawierające co najmniej jedną literę.
Zbiór znaków przekazywany jest do procedury jako napis. Można
założyć, że napis zawiera niepowtarzające znaki będące
literami z zakresu a-z (bez polskich znaków) bądź cyframi 0-9
oraz w napisie występuje co najmniej jedna litera.
Przykład: dla danych ’a2b’ program powinien wypisać zbiory: a,
b, ab, a2, b2, ab2.
*/
using namespace std;

void wypisz_zbiory(string zbior, string podzbior, int element){
    if(element == zbior.size()){
        bool jest_znak = false;
        for(int i = 0; i < podzbior.size(); i++){
            if(!(podzbior[i] >= '0' && podzbior[i] <= '9')){
                jest_znak= true;
                break;
            }
        }
        if(jest_znak)
            cout << podzbior << endl;
        return;
    }

    wypisz_zbiory(zbior, podzbior + zbior.at(element), element+1);
    wypisz_zbiory(zbior, podzbior, element+1);
}
int main() {
    string a = "a2b";
    wypisz_zbiory(a,"",0);
    return 0;
}
