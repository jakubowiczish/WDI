#include <iostream>

using namespace std;

void zamiana(int N, int p)
{
    if(N == 0) return;

    int reszta = N % p;
    N = N/p;
    zamiana(N,p); // rekurencja zeby nie uzywac tablic
    if(reszta < 10){
        cout<<reszta;
    }
    else{
        char litera = reszta + 55; // kod ascii dla reszt 11 - 15
        cout<<litera;
    }
}
int main()
{
    int N, p;
    cout<<"Podaj liczbe: ";
    cin>>N;
    cout<<endl<<"Podaj podstawe systemu na ktory chcesz zamienic liczbe: ";
    cin>>p;
    cout<<"Liczba: "<<N<<" w systemie o podstawie: "<<p<<" to: "<<endl;
    zamiana(N,p);
    return 0;
}
