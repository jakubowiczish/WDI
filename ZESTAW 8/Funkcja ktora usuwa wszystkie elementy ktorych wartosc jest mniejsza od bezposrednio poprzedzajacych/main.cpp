#include <iostream>
/*
Proszê napisaæ funkcjê, otrzymuj¹c¹ jako parametr wskaŸnik na pierwszy element listy o wartoœciach typu int,
usuwaj¹c¹ wszystkie elementy, których wartoœæ jest mniejsza od wartoœci bezpoœrednio poprzedzaj¹cych je elementów.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void print_list(Node *first);
void add(Node*& first, int value);
void deleteSmaller(Node *&first);

int main()
{
    Node *first = nullptr;
    for(int i=20; i >= 0; i--){
        add(first,i);
    }
    for(int i=0; i < 15; i++){
        add(first,i);
    }
    print_list(first);
    deleteSmaller(first);
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

void deleteSmaller(Node *&first)
{
    for(Node *p=first; p -> next != nullptr; p = p -> next){
       for(Node *q=p; q -> next != nullptr; ){
        if((q -> next -> val) > (p -> val)){
            Node *tmp = q -> next;
            q -> next = tmp -> next;
            delete tmp;
        }
        else
            q = q -> next;
       }
    }
}

