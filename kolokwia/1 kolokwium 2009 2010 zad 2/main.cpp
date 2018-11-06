#include <iostream>

/*
Zad. 2 Dana jest tablica typu tab=array[1..n] of integer. Proszê napisaæ funkcjê, która znajdzie
najmniejszy (w sensie liczebnoœci) podzbiór elementów tablicy, dla którego suma elementów jest
równa sumie indeksów tych elementów. Do funkcji nale¿y przekazaæ tablicê, funkcja powinna
zwróciæ sumê elementów znalezionego podzbioru. Na przyk³ad dla tablicy: [ 7, 3, 5, 11, 2 ]
rozwi¹zaniem jest liczba 10.
Uwagi:
• Zawartoœæ tablicy wejœciowej nie mo¿e ulec zmianie.
• Czas na rozwi¹zanie zadania wynosi 25 minut, za zadanie mo¿na otrzymaæ 5 punktów.
• Oceniane bêd¹: przejrzystoœæ i czytelnoœæ kodu oraz efektywnoœæ rozwi¹zania.
*/

using namespace std;
int W[2];
int get(int T[], int tabSize, int start, int sumIndex, int sumValue, int sumCount)
{
    if(sumCount != 0 && sumValue==sumIndex){
        W[0]=sumCount;
        W[1]=sumValue;
        return sumValue;
    }

    int minCount = -1;
    int minSumValue = 0;
    bool isMinimum=false;
    for(int i = start; i < tabSize; i++){
        get(T,tabSize,i+1,sumIndex+(i+1),sumValue+T[i],sumCount+1);
        if(W[0]!=-1){
            if(isMinimum){
                if(W[0] < minCount){
                    minCount=W[0];
                    minSumValue=W[1];
                }
            }
            else {
                minCount=W[0];
                minSumValue=W[1];
                isMinimum=true;
            }
        }
    }
    W[0]=minCount;
    W[1]=minSumValue;
    return minSumValue;
}
int main(int argc, char** argv) {
    int T[]{7,3,5,11,2};
    cout << "MINIMUM " << get(T,5,0,0,0,0) << endl;
    return 0;
}
