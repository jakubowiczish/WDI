#include <iostream>
/*
 Proszê napisaæ program, który wczytuje wprowadzany z klawiatury ci¹g liczb naturalnych
zakoñczonych zerem stanowi¹cym wy³¹cznie znacznik koñca danych.
Program powinien wypisaæ 10 co do wielkoœci wartoœæ, jaka wyst¹pi³a w ci¹gu.
Na przyk³ad dla ci¹gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zostaæ wypisana liczba 3.
Mo¿na za³o¿yæ, ¿e w ci¹gu znajduje siê wystarczaj¹ca liczba elementów
*/
using namespace std;

void print_table(int tab[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void shift_right(int tab[], int N, int shift_start, int inserted_value) {
    cout<< "Shift table right"<< " starting from: " << shift_start<<" element," << "inserting value " << inserted_value<< endl;
    int to_shift;
    int to_insert = inserted_value;

    for (int i = shift_start; i < N; i++)
    {
        to_shift = tab[i];
        tab[i] = to_insert;
        to_insert = to_shift;
    }
}

void shift_left(int tab[], int N, int shift_start, int inserted_value) {
    cout<< "Shift table left"<< " starting from: " << shift_start<<" element," << "inserting value " << inserted_value << endl;
    int to_shift;
    int to_insert = inserted_value;

    for (int i = shift_start; i >= 0; i--)
    {
        to_shift = tab[i];
        tab[i] = to_insert;
        to_insert = to_shift;
    }
}

void shift_right_test(int tab[], int N)
{
    print_table(tab, N);
    shift_right(tab, N, 2,7);
    print_table(tab, N);
    shift_right(tab, N, 0,5);
    print_table(tab, N);
    shift_right(tab, N, N - 1, 0);
    print_table(tab, N);

}

void shift_left_test(int tab[], int N)
{
    shift_left(tab, N, 2,7);
    print_table(tab, N);
    shift_left(tab, N, 0,5);
    print_table(tab, N);
    shift_left(tab, N, N - 1, 3);
    print_table(tab, N);
}

int main()
{
    int N = 10;
    int tab[N] = {1,2,3,4,5,6,7,8,9,10};

    shift_right_test(tab, N);
    shift_left_test(tab, N);

    return 0;
}
