#include <iostream>
/*
Proszê napisaæ funkcjê, która pozostawia w liœcie wy³¹cznie elementy unikalne.
Do funkcji nale¿y przekazaæ wskazanie na pierwszy element listy.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node*& first, int value);
void print_list(Node *first);
void leftUnique(Node *&first);

int main()
{
    Node *first = nullptr;
    for(int i=20; i >= 0; i--){
        add(first,i);
    }
    for(int i=10; i>=0; i--){
        add(first,i);
    }
    print_list(first);
    leftUnique(first);
    print_list(first);
    return 0;
}

void leftUnique(Node *&first)
{
    for(Node *p=first; p -> next != nullptr; p = p -> next){
        for(Node *q = p; q -> next != nullptr; ){
            if(p -> val == q -> next -> val){
                Node *tmp = q -> next;
                q -> next = tmp -> next;
                delete tmp;
            }
            else{
                q = q -> next;
            }
        }
    }
}

void print_list(Node *first)
{
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

void add(Node*& first, int value)
{
    if (first == nullptr) {
        first = new Node;
        first->val = value;
        first->next = nullptr;
    } else {
        Node* new_first = new Node;
        new_first->val = value;
        new_first->next = first;
        first = new_first;
    }
}
