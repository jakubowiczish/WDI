#include <iostream>
/*
Mamy 2 uporz¹dkowane listy jednokierunkowe. Napisz funkcjê, która zwróci wskaŸnik na ró¿nicê
symetryczn¹ z obu list (czyli taki XOR).
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *add_at_beginning_v2(Node *first, Node *new_node);
void print_list(Node *first);
Node *create_node(int value);
Node *MergeLists(Node *&list1, Node *&list2);

int main()
{
    Node *first = new Node;
    first -> val = 5;
    first -> next = nullptr;

    Node *first2 = new Node;
    first2 -> val = 6;
    first2 -> next = nullptr;

    for(int i=30; i>=0; i--){
        first = add_at_beginning_v2(first,create_node(i));
    }
    for(int i=20; i>=0; i--){
        first2 = add_at_beginning_v2(first2,create_node(i));
    }
    print_list(first);
    print_list(first2);
    print_list(MergeLists(first,first2));

    return 0;
}

Node *MergeLists(Node *&list1, Node *&list2)
{
    Node *wartownik = new Node;
    Node *ostatni = wartownik;
    /*
    Node *tmp = list1;
    list1 = list1 -> next;
    delete tmp;
    tmp = list2;
    list2 = list2 -> next;
    delete tmp;
    */
    while(list1 != nullptr and list2 != nullptr)
    {
        if(list1 -> val == list2 -> val){
            Node *tmp = list1;
            list1 = tmp -> next;
            tmp = list2;
            list2 = tmp -> next;
            delete tmp;
        }
        else if(list1 -> val < list2 -> val){
            ostatni -> next = list1;
            list1 = list1 -> next;
        }
        else{
            ostatni -> next = list2;
            list2 = list2 -> next;
        }
        if(ostatni -> next != nullptr){
            ostatni = ostatni -> next;
        }
    }
    if(list1 == nullptr){
        ostatni -> next = list2;
    }
    else{
        ostatni -> next = list1;
    }
    return wartownik;
}

Node *create_node(int value) {
    Node *new_node = new Node;
    new_node->val = value;
    new_node->next = nullptr;
    return new_node;
}

void print_list(Node *first) {
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

Node *add_at_beginning_v2(Node *first, Node *new_node) {
    if(first == nullptr) return new_node;

    new_node->next = first;
    return new_node;
}
