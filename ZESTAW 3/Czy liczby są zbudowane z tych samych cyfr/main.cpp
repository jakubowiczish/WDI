#include <iostream>

using namespace std;

int number_of_digits(int n)
{
    int next = n;
    int counter = 0;
    while(next > 0)
    {
        counter++;
        next /= 10;
    }
    return counter;
}
int counter_of_digits(int n)
{
    const int DIGITS = 10;
    int tab[DIGITS];

    for(int i=0; i<DIGITS; i++)
    {
        tab[i] = 0;
    }
    int next = n;

    while(next > 0)
    {
        int ost = next%10;
        tab[ost]++;
        next /= 10;
    }

    /*for(int i=0; i<number_of_digits(n); i++)
        cout<<tab[i]<<" ";*/
}
int main()
{
    int a,b;
    cin>>a>>b;

    if(counter_of_digits(a) == counter_of_digits(b))
        cout<<"Liczby A i B sa zbudowane z tych samych cyfr"<<endl;
    else
        cout<<"Liczby A i B NIE sa zbudowane z tych samych cyfr"<<endl;
    return 0;
}
