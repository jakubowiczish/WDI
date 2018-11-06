#include <iostream>
/*
Prosze napisac program, który wczytuje liczbe naturalna i odpowiada na pytanie czy cyfry w tej
liczbie sa w porzadku rosnacym (niemalejacym)
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
    int k;
    cin>>k;
    int next = k;
    int ost = 0;

    int num = numberOfDigits(k);
    int tab[num];
    int i = 0;
    while(next > 0)
    {
        ost = next % 10;
        tab[i] = ost;
        i++;
        next /= 10;
    }
    int result = 0;
    int counter = 1;
    cout<<"Liczba odwrocona (rewers): ";
    for(int j=0; j<num; j++)
    {
        cout<<tab[j];
        if(tab[j] >= tab[j+1])
        {
            counter++;
            if(counter == num)
                result = counter;
        }
        else
            counter = 1;
    }
    cout<<endl;
    if(result == num)
        cout<<"TAK, cyfry pierwotnej liczby sa w kolejnosci niemalejacej"<<endl;
    else
        cout<<"NIE, cyfry pierwotnej liczby nie sa w kolejnosci niemalejacej"<<endl;

    return 0;
}
