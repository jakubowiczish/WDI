
#include <iostream>
/*
Proszê napisaæ program, który wczytuje wprowadzany z klawiatury ci¹g liczb naturalnych
zakoñczonych zerem stanowi¹cym wy³¹cznie znacznik koñca danych.
Program powinien wypisaæ te elementy ci¹gu które s¹ równe œredniej arytmetycznej z 4 najbli¿szych
s¹siadów. Na przyk³ad dla ci¹gu: 2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4,0 powinny zostaæ wypisane
podkreœlone liczby. Mo¿na za³o¿yæ, ¿e w ci¹gu znajduje siê co najmniej 5 elementów.
*/
using namespace std;

int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;

    if(a == (double)(b + c + d + e)/4.0)
        cout<<"wypisana: "<<a<<endl;

    if(b == (double)(a + c + d + e)/4.0)
        cout<<"wypisana: "<<b<<endl;

    if(c == (double)(a + b + d + e)/4.0)
        cout<<"wypisana: "<<c<<endl;

    if(d == (double)(a + b + c + e)/4.0)
        cout<<"wypisana: "<<d<<endl;

    if(e == (double)(a + b + c + d)/4.0)
        cout<<"wypisana: "<<e<<endl;


    while(true)
    {
        int temp = a; // TEMP SLUZY TYLKO DO WARUNKOW KONCOWYCH (WTEDY, GDY E == 0) :)

        //AKTUALIZACJA KOLEJNYCH LICZB
        a = b;
        b = c;
        c = d;
        d = e;
        cin>>e;

        if(c == (double)(a + b + d + e)/4.0)
            cout<<"wypisana: "<<c<<endl;

        if(e == 0)
        {
            if(d == (double)(temp + a + b + c)/4.0)
                cout<<"wypisana: "<<d<<endl;

            if(c == (double)(temp + a + b + d)/4.0)
                cout<<"wypisana: "<<c<<endl;

            break;
        }

    }

    return 0;
}
