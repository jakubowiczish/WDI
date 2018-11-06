#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/*
Zad. 2 Dana jest N elementowy zbiór liczb naturalnych w postaci tablicy int t[N]. Proszê napisaæ
funkcjê, która zwraca informacjê czy jest mo¿liwy podzia³ zbioru na trzy zbiory tak aby w ka¿dym z
trzech zbiorów l¹czna liczba jedynek w liczbach zapisanych w systemie binarnym by³a jednakowa. Na
przyk³ad dla zbioru |¯,3,5,7,I1",L3,J-6} mo¿liwy podzia³ to {2,L3,L6} {3,L1i {5,7l czyli w systemie
dwójkowym {10,1101,10000} {11,10LLI |1o1',11'L} - w ka¿dym zbiorze jest 5 jedynek.
*/
int countOnes(int n);
int divide(int a,int b,int c, int k);

const int N = 5;
int tab[N];
int main()
{
    for(int i=0; i < N; i++)
        tab[i] = rand() % 1 + 1;

    cout << divide(0,0,0,0)/6 << endl;
    return 0;
}

int divide(int a,int b,int c, int k)
{
    if(k == N)
         return ((a==b && b==c) ? 1 : 0);
    int j = countOnes(tab[k]);

    return divide(a+j,b,c,k+1) + divide(a,b+j,c,k+1) + divide(a,b,c+j,k+1);
}
int countOnes(int number){ // liczy jedynki w zapisie binarnym
    int result = 0;

    while(number > 0){
        result += number%2;
        number /= 2;
    }
    return result;
}
