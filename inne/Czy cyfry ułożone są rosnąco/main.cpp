#include <iostream>
/*
Proszê napisaæ program, który wczytuje dwie liczby naturalne (ka¿da wiêksza od 10) i
odpowiada na pytanie czy w liczbie bêd¹cej sum¹ wczytanych liczb cyfry u³o¿one s¹ rosn¹co. Na
przyk³ad dla liczb 13411 i 68 – TAK, dla liczb 2500 i 57 – NIE
*/

using namespace std;

int numberOfDigits(int n)
{
    int next = n;
    int counter = 0;
    while(next > 0)
    {
        next /= 10;
        counter++;
    }
    return counter;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int sum = a + b;

    int temp = sum; // zmienna tymczasowa na sume

    int cyfry[numberOfDigits(sum)]; // tablica na cyfry liczby
    int counter = 1; // zlicza ile cyfr jest wiekszych od siebie po kolei

    for(int i=0; i<numberOfDigits(sum); i++)
    {
        cyfry[i] = temp % 10;
        temp /= 10;

    }

    for(int i=0; i<numberOfDigits(sum); i++)
    {
        if(cyfry[i] > cyfry[i+1])
        {
            counter++;
        }
    }
    cout<<endl;
    if(counter == numberOfDigits(sum))
    {
        cout<<"TAK, cyfry sumy sa uporzadkowane rosnaco"<<endl;
    }
    else
    {
        cout<<"NIE, cyfry sumy nie sa uporzadkowane rosnaco"<<endl;
    }
    return 0;
}
