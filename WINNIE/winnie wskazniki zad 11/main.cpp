#include <iostream>
///Proszê napisac funkcje, która podanej listy odwraca kolejnosc jej elementów
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node*& first, int value);
Node* chainInverse(Node *&first);
void print_list(Node *first);

int main()
{
    Node *first = nullptr;
    for(int i=50; i >= 0; i--){
        add(first,i);
    }
    print_list(first);
    chainInverse(first);
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

Node* chainInverse(Node *&first)
{
    Node *p =nullptr;
    Node *q = nullptr;

    while(first != nullptr){
        p = first;
        first = first -> next;
        p -> next = q;
        q = p;
    }
    first = q;
    return first;
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
