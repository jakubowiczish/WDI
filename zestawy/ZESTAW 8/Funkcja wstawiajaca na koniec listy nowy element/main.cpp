#include <iostream>
/*Proszê napisaæ funkcjê wstawiaj¹c¹ na koniec listy nowy element.
Do funkcji nale¿y przekazaæ wskazanie na pierwszy element listy oraz wstawian¹ wartoœæ.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void print_list(Node *first);
void add(Node *&first, int value);

int main()
{
    Node *first = nullptr;
    add(first,5);
    print_list(first);
    return 0;
}

void print_list(Node *first)
{
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

void add(Node *&first, int value)
{
    if(first == nullptr){
        first = new Node;
        first -> val = value;
        first -> next = nullptr;
    }else{
        Node *new_first = new Node;
        new_first -> val = value;
        new_first -> next = first;
        first = new_first;
    }
}
