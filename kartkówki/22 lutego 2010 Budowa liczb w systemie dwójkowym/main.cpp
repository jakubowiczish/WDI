#include <iostream>
using namespace std;
/*
Zad. 2 Do budowy liczby naturalnej reprezentowanej w systemie dwójkowym mo¿emy u¿yæ A cyfr
1 oraz B cyfr 0, gdzie A,B>0. Proszê napisaæ funkcjê, która dla zadanych parametrów A i B zwraca
iloœæ wszystkich mo¿liwych do zbudowania liczb, takich ¿e pierwsza cyfra w systemie dwójkowym
(najstarszy bit) jest równa 1, a zbudowana liczba jest z³o¿ona.
Na przyk³ad dla A=2, B=3 iloœæ liczb wynosi 3, s¹ to 10010(2) 10100(2) 11000(2)
Uwagi:
• Czas na rozwi¹zanie zadania wynosi 25 minut, za zadanie mo¿na otrzymaæ 5 punktów.
• Oceniane bêd¹: przejrzystoœæ i czytelnoœæ kodu oraz efektywnoœæ rozwi¹zania.
*/
void buduj(int a, int b, int &ilosc);
int zadanie(int a, int b);

int main()
{
    int a,b;
    cin >> a >> b;
    cout << zadanie(a,b);
    return 0;
}

void buduj(int a, int b, int &ilosc)
{
    if(a == 0 && b == 0){
        ilosc++;
        return;
    }

    if(a > 0) buduj(a-1,b,ilosc);
    if(b > 0) buduj(a,b-1,ilosc);
}

int zadanie(int a, int b)
{
    int ilosc = 0;
    buduj(a-1,b,ilosc); // a-1 bo zaczynamy kazda liczbe od jedynki
    return ilosc;
}

