#include <iostream>
/*
Mamy cykliczna liste zawieraj¹c¹ liczby calkowite. Ka¿da pierwsza cyfra kolejnej liczby jest równa
ostatniej cyfrze poprzedniej liczby.
np. 123 - 324 - 435 - 578 -> lañcuch siê zapêtla
Napisz funkcjê wstawiaj¹c¹ liczbê do listy. Liczba ma zastapiæ dwa juz istniejace elementy cyklu.
dla przyk³adu tutaj, za (324 - 435) mo¿na wstawiæ 35
Funkcja powinna zwróciæ wartosc logiczna w zaleznoœci od tego czy próba wstawiania zakoñczyla siê
sukcesem
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int LastNumber(int n)
{
    return n%10;
}

int FirstNumber(int n)
{
    int a;
    while(n > 0){
        a = n%10;
        n /= 10;
    }
    return a;
}

bool instertChain(Node *&first, int value)
{
    int firstN = FirstNumber(value);
    int lastN = LastNumber(value);
    Node *p = first;
    while(p -> next != nullptr){
        if(FirstNumber(p -> next -> val) == firstN and LastNumber(p-> next-> next -> val) == lastN){
            p -> next -> val = value;
            Node *tmp = p -> next -> next;
            p -> next -> next = tmp -> next;
            delete tmp;
            return true;
        }
        p = p -> next;
    }
    return false;
}

