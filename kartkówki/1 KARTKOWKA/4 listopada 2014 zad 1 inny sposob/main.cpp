#include <iostream>
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
    int nowe[10] = {0,0,0,0,0,0,0,0,0,0};
    int liczba;
    cin>>liczba;
    nowe[0] = liczba;
    while(liczba != 0)
    {
        cin>>liczba;
        while(liczba > nowe[0])
        {
            for(int j=9; j>=1; j--)
            {
                nowe[j] = nowe[j-1];
            }/*
            nowe[9] = nowe[8];
            nowe[8] = nowe[7];
            nowe[7] = nowe[6];
            nowe[6] = nowe[5];
            nowe[5] = nowe[4];
            nowe[4] = nowe[3];
            nowe[3] = nowe[2];
            nowe[2] = nowe[1];
            nowe[1] = nowe[0];*/
            nowe[0] = liczba;
        }

        cout<<"Cala nowa tablica: "<<endl;
        for(int j=0; j<10; j++)
        {
            cout<<nowe[j]<<" ";
        }
        cout<<endl;
    }

    /*cout<<"Cala nowa tablica: "<<endl;
    for(int j=0; j<10; j++)
    {
        cout<<nowe[j]<<" ";
    }*/
    cout<<endl<<"10 w kolejnosci element: "<<nowe[9]<<endl;
    return 0;
}
