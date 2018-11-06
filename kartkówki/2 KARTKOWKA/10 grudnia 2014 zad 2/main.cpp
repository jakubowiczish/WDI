#include <iostream>
using namespace std;
/*
2. Dane s¹ dwie liczby naturalne z których budujemy trzeci¹ liczbê. W budowanej liczbie musz¹
wyst¹piæ wszystkie cyfry wystêpuj¹ce w liczbach wejœciowych. Wzajemna kolejnoœæ cyfr ka¿dej z liczb
wejœciowych musi byæ zachowana. Na przyk³ad maj¹c liczby 123 i 75 mo¿emy zbudowaæ liczby 12375,
17523, 75123, 17253, itd. Proszê napisaæ funkcjê która wyznaczy ile liczb pierwszych mo¿na
zbudowaæ z dwóch zadanych liczb.
*/
void wygeneruj(int a, int b, int c, int n, int &ilosc);
int zadanie(int a, int b);
bool isPrime(int n);

int main()
{
    int a,b;
    cin >> a >> b;
    cout << zadanie(a,b);
    return 0;
}

// a - liczba nr 1
// b - liczba nr 2
// c = generowana liczba
// n = czynnik, mnozymy go razy 10 zeby dodawac cyfry do generowanej liczby
// ilosc = ilosc liczb
void wygeneruj(int a, int b, int c, int n, int &ilosc)
{
    if(a == 0 && b == 0){
        cout << c << endl;
        if(isPrime(c)){
            ilosc++;
        }
        return;
    }

    if(a > 0) wygeneruj(a/10,b,c + n*(a%10),n*10,ilosc);
    if(b > 0 && b%10 != a%10) wygeneruj(a,b/10,c + n*(b%10),n*10,ilosc);
}

int zadanie(int a, int b)
{
    int ilosc = 0;
    cout << "Wygenerowane liczby: " << endl;
    wygeneruj(a,b,0,1,ilosc);
    return ilosc;
}
bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
