#include <iostream>
/*
 * Dane są dwa niepuste łańcuchy odsyłaczowe [jednokierunkowe] przechowujące liczby
naturalne. W pierwszym liczby są uporządkowane rosnąco, a w drugim malejąco. Proszę
napisać odpowiednie definicje typów oraz funkcję scalającą takie dwa łańcuchy w jeden
zawierający posortowane rosnąco elementy. Funkcja powinna zwrócić wskaźnik do nowego
łańcucha
 */

using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *add_at_beginning_v2(Node *first, Node *new_node);
void print_list(Node *first);
Node *create_node(int value);
Node *scalajRosnaco(Node *&list1, Node *&list2);


int main()
{
    Node *first = new Node;
    first -> val = 0;
    first -> next = nullptr;
    Node *first2 = new Node;
    first2 -> val = 0;
    first -> next = nullptr;
    for(int i=30; i>=20; i--){
        first = add_at_beginning_v2(first,create_node(i));
    }
    for(int i=0; i<10; i++){
        first2 = add_at_beginning_v2(first2,create_node(i));
    }
    print_list(first);
    print_list(first2);
    scalajRosnaco(first,first2);
    print_list(first);
    print_list(first2);
    return 0;
}

Node* Scalanie(Node* &list1, Node* &list2) // list1 - rosn¹ca , list2 - malej¹ca.
{
    Node* p = nullptr;
    Node* q = nullptr;
    while(list2!=nullptr) // odwrócenie listy malej¹cej
    {
        p=list2;
        list2=list2->next;
        p->next=q;
        q=p;
    }
    list2=q; // lista odwrócona
    Node* list=nullptr, *last=nullptr;

    while(list1!=nullptr and list2!=nullptr)
    {
        int a=list1->val;
        int b=list2->val;

        if(a<b)
        {
            Node* tmp=list1;
            list1=list1->next;
            tmp->next=nullptr;
            if(last!=nullptr) last->next=tmp;
            else list=tmp;
            last=tmp;
        }
        if(a>b)
        {
            Node* tmp=list2;
            list2=list2->next;
            tmp->next=nullptr;
            if(last!=nullptr) last->next=tmp;
            else list=tmp;
            last=tmp;

        }
        if(a==b)
        {
            Node* tmp=list1;
            list1=list1->next;
            tmp->next=nullptr;
            if(last!=nullptr) last->next=tmp;
            else list=tmp;
            last=tmp;
            Node* tmp2=list2;
            list2=list2->next;
            delete tmp2;
        }
        last->next= list2==nullptr ? list1 : list2;
    }
    list1=nullptr;
    list2=nullptr;
    return list;
}

Node *create_node(int value)
{
    Node *new_node = new Node;
    new_node->val = value;
    new_node->next = nullptr;
    return new_node;
}

void print_list(Node *first)
{
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

Node *add_at_beginning_v2(Node *first, Node *new_node)
{
    if(first == nullptr) return new_node;

    new_node->next = first;
    return new_node;
}
