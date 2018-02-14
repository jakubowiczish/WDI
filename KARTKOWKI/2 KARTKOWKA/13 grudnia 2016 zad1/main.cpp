#include <iostream>

using namespace std;
/*
Dana jest liczba naturalna N niezawieraj¹ca cyfry 0, któr¹ rozbijamy na dwie liczby naturalne
A i B, przenosz¹c kolejne cyfry z liczby N do liczby A albo B. Na przyk³ad liczbê 21523
mo¿emy rozbiæ na wiele sposobów, np. (215,23),(2,1523),(223,15),(152,23),(22,153),(1,2523)...
Uwaga: wzglêdna kolejnoœæ cyfr w liczbie N oraz liczbach A i B musi byæ zachowana. Proszê
napisaæ funkcjê generuj¹c¹ i wypisuj¹c¹ wszystkie rozbicia, w których powsta³e liczby A i B
s¹ wzglêdnie pierwsze. Do funkcji nale¿y przekazaæ wartoœæ N, funkcja powinna zwróciæ liczbê
znalezionych par.
Uwagi:
- warunek wzglêdnej pierwszoœci mo¿na pomin¹æ kosztem 1 pkt
- do funkcji mo¿na przekazaæ dodatkowe parametry
- czas na rozwi¹zanie obu zadañ wynosi 45 minut
- za ka¿de zadanie mo¿na otrzymaæ maksymalnie 5 pkt
- oceniane bêd¹: czytelnoœæ, poprawnoœæ i efektywnoœæ rozwi¹zañ
*/
int gcd(int a, int b)
{
    while(b != 0)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int reversed(int n)
{
    int r = 0;
    while(n > 0)
    {
        r = (10*r) + (n%10);
        n/=10;
    }
    return r;

}

int generate_recursive(int src, int a, int b, int last_added_to_a)
{
    if(src == 0)
    {
        if(a != 0 && b != 0 && gcd(a,b) == 1)
        {
            cout << a << ',' << b <<endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int digit = src%10;
    int new_src = src/10;

    int new_a = (10*a) + digit;
    int new_b = (10*b) + digit;

    int result = 0;
    result += generate_recursive(new_src,new_a,b,digit);

    if(digit != last_added_to_a)
    {
        result += generate_recursive(new_src,a,new_b,digit);
    }

    return result;
}

int generate(int n)
{
    n = reversed(n);
    return generate_recursive(n,0,0,-1);
}
int main()
{
    int n;
    cin >> n;
    cout<<generate(n);
    return 0;
}
