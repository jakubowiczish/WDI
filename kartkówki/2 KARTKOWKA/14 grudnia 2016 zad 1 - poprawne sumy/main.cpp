#include <iostream>
using namespace std;
/*
1. Dane s¹ dwie tablice t1[N] i t2[N] zawieraj¹ce liczby naturalne. Z wartoœci w obu tablicach
mo¿emy tworzyæ sumy. „Poprawna” suma to taka, która zawiera co najmniej jeden element
(z tablicy t1 lub t2) o ka¿dym indeksie. Na przyk³ad dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8]
poprawnymi sumami s¹ na przyk³ad 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8.
Proszê napisaæ funkcjê generuj¹c¹ i wypisuj¹c¹ wszystkie poprawne sumy, które s¹ liczbami
pierwszymi. Do funkcji nale¿y przekazaæ dwie tablice, funkcja powinna zwróciæ liczbê
znalezionych i wypisanych sum.
Uwagi:
- warunek pierwszoœci mo¿na pomin¹æ kosztem 1 pkt
- do funkcji mo¿na przekazaæ dodatkowe parametry
- czas na rozwi¹zanie obu zadañ wynosi 45 minut
- za ka¿de zadanie mo¿na otrzymaæ maksymalnie 5 pkt
- oceniane bêd¹: czytelnoœæ, poprawnoœæ i efektywnoœæ rozwi¹zañ
*/const int N = 4;
int valid_sum(int tab1[],int tab2[],int i, int sum);
bool isPrime(int n);

int main()
{
    int tab1[N] = {1,3,2,4};
    int tab2[N] = {9,7,4,8};
    cout << "Ilosc: " << valid_sum(tab1,tab2,0,0) << endl;
    return 0;
}

// tab1, tab2 - tablice
// sum - generowana suma
// i - indeks
// ilosc - ilosc wygenerowanych poprawnych sum
int valid_sum(int tab1[],int tab2[],int i, int sum)
{
    if(i == N)
    {
        if(isPrime(sum))
        {
            cout << sum << endl;
            return 1;
        }
        return 0;
    }
    else
    {
        return valid_sum(tab1,tab2,i+1,sum + tab1[i]) +
                   valid_sum(tab1,tab2,i+1,sum + tab2[i]) +
                   valid_sum(tab1,tab2,i+1,sum + tab1[i] + tab2[i]);
    }
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
