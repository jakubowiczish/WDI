#include <iostream>
/*
Kolejne elementy listy o zwiêkszaj¹cej siê wartoœci pola val nazywamy podlist¹ rosn¹c¹. Proszê
napisaæ funkcjê, która usuwa z listy wejœciowej najd³u¿sz¹ podlistê rosn¹c¹. Warunkiem usuniêcia jest
istnienie w liœcie dok³adnie jednej najd³u¿szej podlisty rosn¹cej.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node*& first, int value);
void print_list(Node *first);
void longestSequence(Node *&first);

int main()
{
    Node *first = nullptr;
    for(int i=20; i >=0; i--){
        add(first,i);
    }
    for(int i=0; i < 10; i++){
        add(first,i);
    }
    print_list(first);
    longestSequence(first);
    print_list(first);
    return 0;
}

void longestSequence(Node *&first)
{
    int actualLength = 1;
    int maxLength = 1;
    Node *result = nullptr;

    for(Node *p=first; p -> next != nullptr; p = p-> next){
        for(Node *q=p; q -> next != nullptr; ){
            if((q -> next -> val) > (p -> val)){
                actualLength++;
            }
            else {
                if(actualLength > maxLength){
                    maxLength = actualLength;
                    result = p;
                }
                actualLength = 1;
            }
            q = q -> next;
        }
    }

    for(Node *p=first; p -> next != nullptr; p = p -> next){
        if(p == result){
        	Node *q = p -> next;
            while(q->next != nullptr && (q  -> next -> val) > (q -> val)){
                Node *tmp = q;
                q = q -> next;
                delete tmp;
            }
            p->next = q->next;
            return;
        }

    }

    cout << maxLength << endl;
    cout << result -> val << endl;
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

void print_list(Node *first)
{
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}
