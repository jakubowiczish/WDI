#include <iostream>
#include <algorithm>
#include <vector>
/*
Proszê napisaæ program, który wczytuje wprowadzany z klawiatury ci¹g liczb naturalnych
zakoñczonych zerem stanowi¹cym wy³¹cznie znacznik koñca danych.
Program powinien wypisaæ 10 co do wielkoœci wartoœæ, jaka wyst¹pi³a w ci¹gu.
Na przyk³ad dla ci¹gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zostaæ wypisana liczba 3.
Mo¿na za³o¿yæ, ¿e w ci¹gu znajduje siê wystarczaj¹ca liczba elementów.
*/
using namespace std;

int main()
{
    vector <int> liczby;
    int liczba;
    cin>>liczba;
    while(liczba != 0)
    {
        cin>>liczba;
        liczby.push_back(liczba);
        sort(liczby.begin(),liczby.end());
    }
    int index = liczby.size()-1;

        for(int i = 0; i < 9; i++)
        {
            int liczbaTemp = liczby[index];
            index--;
            while(liczbaTemp == liczby[index])
            {
                 index--;
            }
        }

    for(unsigned int i=0; i<liczby.size(); i++)
        cout<<liczby.at(i)<<" ";
    cout<<endl;
    cout<<liczby[index]<<endl;
    cout<<index<<endl;

    return 0;
}
