#include <iostream>
/*
 Dane s¹ dwa jednokierunkowe ³añcuchy odsy³aczowe (listy) zbudowane z elementów:
 struct node { int w; node* next; };
Ka¿dy ³añcuch zawiera niepowtarzaj¹ce siê liczby naturalne. W obu ³añcuchach liczby s¹ posortowane rosn¹co.
Proszê napisaæ funkcjê usuwaj¹c¹ z ka¿dego ³añcucha liczby nie wystêpuj¹ce w drugim. Do funkcji nale¿y przekazaæ
wskazania na oba ³añcuchy, funkcja powinna zwróciæ ³¹czn¹ liczbê usuniêtych elementów.
*/
using namespace std;
struct Node{
    int val;
    Node *next;
};

Node *create_node(int value);
void print_list(Node *first);
Node *add_at_beginning_v2(Node *first, Node *new_node);
void add(Node*& first, int value);
int removeCommonValues(Node *&first1, Node *&first2);
void removeValue(Node *&first, int value);

int main()
{
    Node *f1 = nullptr;
    Node *f2 = nullptr;

    for(int i=10; i>=0; i--){
        add(f1,i);
    }
    for(int i=2; i<6; i++){
        add(f2,i);
    }
    print_list(f1);

    print_list(f2);
    cout << "Removed: " << removeCommonValues(f1,f2) << endl;
    print_list(f1);
    print_list(f2);
    return 0;
}

int removeCommonValues(Node *&first1, Node *&first2)
{
    int removed = 0;
    Node *it1;
    Node *it2;

    it1 = first1;
    while(it1 != nullptr){
        it2 = first2;
        while(it2 != nullptr){
            if(it1 -> val == it2 -> val){
                removeValue(first1, it1 -> val);
                removeValue(first2, it2 -> val);

                removed += 2;
            }
            it2 = it2 -> next;
        }
        it1 = it1 -> next;
    }
    return removed;
}

void removeValue(Node *&first, int value)
{
    Node *it = first;
    Node *prev = nullptr;

    while(it != nullptr)
    {
        if(it -> val == value){
            if(prev == nullptr){
                first = first -> next;
            }
            else{
                prev -> next = it -> next;
                delete it;
            }
        }
        prev = it;
        it = it -> next;
    }
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
