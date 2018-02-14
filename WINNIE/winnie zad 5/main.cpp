#include <iostream>
#include <iomanip>

using namespace std;

void ulamek(double l, double m, double accuracy)
{
    cout<<setprecision(accuracy)<<fixed<<l/m<<endl;
}

int main()
{
    int a,b,c;
    cout<<"Podaj licznik: ";
    cin>>a;
    cout<<"Podaj mianownik: ";
    cin>>b;
    cout<<"Podaj dokladnosc: ";
    cin>>c;
    ulamek(a,b,c);
    return 0;
}
