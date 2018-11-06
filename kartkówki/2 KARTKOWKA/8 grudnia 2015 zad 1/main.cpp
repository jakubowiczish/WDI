#include <iostream>
/*
1) Dane s¹ trzy operacje na liczbach naturalnych oznaczone literami ¥B,C.
A. je¿eli liczba posiada co najmniej 2 cyfry zamienia miejscami dwie ostatnie cyfry w liczbie;
B. mno¿y liczbê przez3;
c. je¿eli liczba posiada co najmniej 2 cyfry usuwa pierwsz¹ cyfrê z liczby.
Proszê napisaæ funkcjê, która szuka sekwencji operacji przekszta³caj¹cej liczbê naturaln¹ x na y (x!=y) o d³ugoœci nie wiêkszej ni¿ 7.
Do funkcji nale¿y przekazaæ liczby x, y.
Funkcja powinna zwróciæ napis z³o¿ony z liter ABC realizuj¹cy przekszta³cenie albo ³añcuch pustyje¿eli
przekszta³cenie nie istnieje. Na przyk³ad dla liczb 6,3 funkcja powinna zwróciæ napis "BACB".
Uwagi:
o do funkcji mo¿na przekazaæ dodatkowe parametry.
. czas na rozwi¹zanie zadañ wynosi 40 min .
o za ka¿de zadanie mo¿na otrzymaæ maksymalnie 5 pkt.
o oceniane bêd¹: czytelnoœæ, poprawnoœæ i efektywnoœæ rozwi¹zañ.
*/
using namespace std;

int rever(int n);
bool find_operations_check(int x, int y, char seq[], int i);
string find_operations(int x, int y);

int main()
{
    int a,b;
    cin >> a >> b;
    cout << find_operations(a,b) << endl;
    return 0;
}

string find_operations(int x, int y)
{
    char sequence[8];
    if(find_operations_check(x,y,sequence,0)){
        return string(sequence);
    }
    else{
        return "";
    }
}

bool find_operations_check(int x, int y, char seq[], int i)
{
    if(x == y){
        seq[i] = '\0';
        return true;
    }
    if(i == 7){
        return false;
    }
    if(x >= 10){
        seq[i] = 'C';
        int x2 = x;
        x2 = rever(x2);
        x2 /= 10;
        x2 = rever(x2);
        if(find_operations_check(x2,y,seq,i+1)){
            return true;
        }
    }

    if(x >= 10){
        seq[i] = 'A';
        int digit_of_unity = x%10;
        int digit_of_tens = (x/10)%10;
        int rest = x / 100;
        int x2 = 100*rest + 10*digit_of_unity + digit_of_tens;

        if(find_operations_check(x2,y,seq,i+1)){
            return true;
        }
    }
    seq[i] = 'B';
    if(find_operations_check(3*x,y,seq,i+1)){
        return true;
    }

    return false;
}

int rever(int n)
{
    int next = 0;
    while(n > 0)
    {
        next = next*10 + n%10;
        n /= 10;
    }
    return next;
}
