#include <iostream>
/*
Dany jest typ:
type
pnode=^node;
node=record
klucz:integer;
next:pnode;
end;
Proszê napisaæ procedurê rozdzielaj¹c¹ ³añcuch na 2 ³añcuchy wed³ug klucza, w taki sposób,
¿e w pierwszym ³añcuchu znajd¹ siê liczby, które s¹ wielokrotnoœci¹ kwadratu
liczby pierwszej, a w drugim pozosta³e.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *create_node(int value);
void print_list(Node *first);
Node *add_at_beginning_v2(Node *first, Node *new_node);
bool isMultipleSquareOfPrime(int n);
void splitList(Node *source, Node *&fancyGuys, Node *&others);
void split(Node* src, Node*& matching, Node*& others) ;

int main()
{
    Node *first = new Node;
    first -> val = 10;
    first -> next = nullptr;

    for(int i=50; i>=0; i--){
        first = add_at_beginning_v2(first,create_node(i));
    }
    cout << "Pierwotny lancuch:" << endl << endl;
    print_list(first);
    cout << endl;
    Node *fancyGuys = new Node;
    fancyGuys -> val = 0;
    fancyGuys -> next = nullptr;

    Node *others = new Node;
    others -> val = 0;
    others -> next = nullptr;

    splitList(first,fancyGuys,others);
    cout << "Lancuch z wielokrotnosciami kwadratow: " << endl << endl;
    print_list(fancyGuys);
    cout << endl;
    cout << "Pozostale liczby: " << endl << endl;
    print_list(others);
    cout << endl;
    return 0;
}

void splitList(Node *source, Node *&fancyGuys, Node *&others)
{
    fancyGuys = nullptr;
    others = nullptr;
    Node *fancyGuysEnd = nullptr;
    Node *othersEnd = nullptr;

    while(source != nullptr)
    {
        if(isMultipleSquareOfPrime(source -> val)){
            if(fancyGuys == nullptr){
                fancyGuys = source;
            }
            else{
                fancyGuysEnd -> next = source;
            }
            fancyGuysEnd = source;
        }
        else{
            if(others == nullptr){
                others = source;
            }
            else{
                othersEnd -> next = source;
            }
            othersEnd = source;
        }
        source = source -> next;
    }
    if(fancyGuysEnd != nullptr){
        fancyGuysEnd -> next = nullptr;
    }
    if(othersEnd != nullptr){
        othersEnd -> next = nullptr;
    }
}

bool isMultipleSquareOfPrime(int n)
{
    if(n < 2)
        return false;
    int i = 2;
    while(i * i <= n){
        if(n%(i*i) == 0){
            return true;
        }
        i++;
    }
    return false;
}

Node *add_at_beginning_v2(Node *first, Node *new_node)
{
    if(first == nullptr) return new_node;

    new_node->next = first;
    return new_node;
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
