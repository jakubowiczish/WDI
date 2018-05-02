
#include <iostream>
/*
 Proszê napisaæ funkcjê, która otrzymuj¹c jako parametr wskazuj¹cy na pocz¹tek listy
jednokierunkowej, przenosi na pocz¹tek listy te z nich, które maj¹ parzyst¹ iloœæ pi¹tek w zapisie
ósemkowym.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *create_node(int value);
void print_list(Node *first);
void add(Node*& first, int value);
void modifyChain(Node *first);
bool evenNumberOf5(int n);

int main()
{
    Node *first = nullptr;
    for(int i=30; i >= 0; i--){
        add(first,i);
    }
    cout << "Chain before changes: " << endl << endl;
    print_list(first);
    modifyChain(first);
    cout << "Chain after changes: " << endl << endl;
    print_list(first);
    return 0;
}

bool evenNumberOf5(int n)/// zrobione dla dziesietnego
{
    int counter5 = 0;
    while(n > 0){
        if(n%10 == 5)
            counter5++;
        n /= 10;
    }
    return counter5;
}

void modifyChain(Node *first)
{
    Node *some = new Node;
    some -> next = first;
    for(Node *p=first; p -> next != nullptr; )
    {
        if(evenNumberOf5(p -> next -> val))
        {
            Node *tmp = p -> next;
            p -> next = tmp -> next;
            tmp -> next = first;
            first = tmp;
            some -> next = tmp;
        }
        else
            p = p -> next;
    }
    cout << "List after the start of modifying: " << endl << endl;
    print_list(some);
    delete some;
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
