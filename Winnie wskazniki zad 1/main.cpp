#include <iostream>
/*
Dane s¹ deklaracje opisuj¹ce listê jednokierunkow¹:
type
pwezel = ^wezel;
wezel = record
val: integer;
next: pwezel
end;
Proszê napisaæ procedurê, która w liœcie wskazywanej przez zmienna typu pwezel usuwa
powtarzaj¹ce siê elementy. Mo¿na za³o¿yæ, ¿e lista jest niepusta.
*/
struct Node{
    int val;
    Node *next;
};
using namespace std;

Node *create_node(int value);
void print_list(Node *first);
void deleteDuplicatedOnes(Node *first);
Node *add_at_beginning_v2(Node *first, Node *new_node);

int main()
{
    Node *first = new Node;
    first -> val = 5;
    first -> next = nullptr;
    for(int i=0; i < 10; i++){
        first = add_at_beginning_v2(first,create_node(i));
    }
    for(int i=3; i < 7; i++){
        first = add_at_beginning_v2(first,create_node(i));
    }
    cout << "Original list: " << endl;
    print_list(first);
    deleteDuplicatedOnes(first);
    cout << "Changed list: " << endl;
    print_list(first);
    return 0;
}

void deleteDuplicatedOnes(Node *first)
{
    for(Node *p = first; p -> next != nullptr; p= p -> next)
    {
        for(Node *q = p; q -> next != nullptr; )
        {
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
