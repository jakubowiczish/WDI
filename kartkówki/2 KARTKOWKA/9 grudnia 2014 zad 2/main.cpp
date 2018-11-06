#include <iostream>
/*
. Wyrazy budowane s¹ z liter a..z. Dwa wyrazy „wa¿¹” tyle samo je¿eli: maj¹ tê sam¹ liczbê
samog³osek oraz sumy kodów ascii liter z których s¹ zbudowane s¹ identyczne, na przyk³ad „ula” ->
117 108 97 oraz „exe” 101 120 101. Proszê napisaæ funkcjê bool wyraz( string s1, string s2), która
sprawdza czy jest mo¿liwe zbudowanie wyrazu z podzbioru liter zawartych w s2 wa¿¹cego tyle co
wyraz s1. Dodatkowo funkcja powinna wypisaæ znaleziony wyraz.
*/
using namespace std;

bool samogloska(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') return true;
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y') return true;
    return false;
}

bool wyraz2(int samogloskiW1, int sumaW1, string zbior, string aktualny, int samogloski, int suma){
    if(samogloski == samogloskiW1 && suma == sumaW1){
        cout << aktualny;
        return true;
    }
    if(samogloski > samogloskiW1) return false;
    if(suma > sumaW1) return false;

    for(int i = 0; i < zbior.length(); i++){
        bool isSamogloska = samogloska(zbior[i]);
        if(isSamogloska){
            if(wyraz2(samogloskiW1,sumaW1,zbior,aktualny+zbior[i], samogloski+1, suma+zbior[i])) return true;
        }
        else {
            if(wyraz2(samogloskiW1,sumaW1,zbior,aktualny+zbior[i], samogloski, suma+zbior[i])) return true;
        }
    }
}
int sumaASCII(string w){
    int suma = 0;
    for(int i = 0; i < w.length(); i++){
        suma += w[i];
    }
    return suma;
}

bool wyraz(string s1, string s2){
    int samogloskiW1 = 0;
    for(int i = 0; i < s1.length(); i++){
        if(samogloska(s1[i])) samogloskiW1++;
    }
    int sumaW1 = sumaASCII(s1);

    return wyraz2(samogloskiW1, sumaW1, s2, "", 0,0);
}

int main() {
    int test = (int)'A';
    cout << wyraz("ula", "xe");
    return 0;
}
