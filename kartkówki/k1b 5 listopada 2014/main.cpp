#include <iostream>
#include <vector>
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
    vector<int> liczby;
    int liczba;
    while(true)
    {
        cin>>liczba;
        if(liczba == 0)
            break;
        liczby.push_back(liczba);
    }
    for(int i=0; i<liczby.size(); i++)
    {
        if((i >= 2 && i<= liczby.size() - 3) && liczby[i] == (liczby[i-2] + liczby [i-1] + liczby[i+1] + liczby[i+2]) / 4.0 ) // standardowy przyklad
           {
               cout<<liczby[i]<<" ";
           }

        if((i == 1) && liczby[i] == (liczby[i-1] + liczby [i+1] + liczby[i+2] + liczby[i+3]) / 4.0) // liczba nr 2
           {
               cout<<liczby[i]<<" ";
           }

        if((i == liczby.size() - 2) && liczby[i] == (liczby[i-3] + liczby [i-2] + liczby[i-1] + liczby[i+1]) / 4.0)  // przedostatnia
           {
               cout<<liczby[i]<<" ";
           }
        if((i == liczby.size() -1) && liczby[i] == (liczby[i-4] + liczby [i-3] + liczby[i-2] + liczby[i-1]) / 4.0) // ostatnia
           {
               cout<<liczby[i]<<" ";
           }

        if((i == 0) && liczby[i] == (liczby[i+1] + liczby [i+2] + liczby[i+3] + liczby[i+4]) / 4.0)  // pierwsza
           {
               cout<<liczby[i]<<" ";
           }
    }
    return 0;
}
