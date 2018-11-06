#include <iostream>
/*
Proszê napisaæ funkcjê, otrzymuj¹c¹ jako parametr wskaŸnik na pierwszy element listy o wartoœciach typu int,
usuwaj¹c¹ wszystkie elementy, których wartoœæ dzieli bez reszty wartoœæ bezpoœrednio nastêpuj¹cych po nich elementów.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void print_list(Node *first);
void removeElements(Node *&first);
void add(Node*& first, int value);

int main()
{
    Node *first = nullptr;
    for(int i=0; i < 130; i += 10){
        add(first,i);
    }
    print_list(first);
    removeElements(first);
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

void removeElements(Node *&first)
{
    for(Node *p=first; p -> next != nullptr; p = p -> next){
        if((p -> val)%(p -> next ->  val) == 0){
            Node *tmp = p -> next;
            p -> next = tmp -> next;
            delete tmp;
        }
    }
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
