#include <iostream>
/*
Napisz funkcjê, która przyjmuje wskaŸnik do pocz¹tku jednokierunkowego
³añcucha odsy³aczowego, a nastêpnie przenosi na pocz¹tek wszystkie elementy,
w których zapisie ósemkowym wystêpuje nieparzysta liczba pi¹tek.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

Node *add_at_beginning_v2(Node *first, Node *new_node);
Node *create_node(int value);
void print_list(Node *first);
bool isOddNumberOfFives(int n);
void migrate(Node *list);

int main()
{
    Node *first = new Node;
    first -> val = 5;
    first -> next = nullptr;

    for(int i=20; i>=0; i--){
        first = add_at_beginning_v2(first,create_node(i));
    }
    print_list(first);
    migrate(first);
    print_list(first);
    return 0;
}

bool isOddNumberOfFives(int n)
{
    int counter = 0;
    while(n > 0){
        if(n%10 == 5){
            counter++;
        }
        n /= 10;
    }
    if(counter%2 == 0){
        return false;
    }
    return true;
}

void migrate(Node *list)
{
    Node *last;
    last = new Node;
    last -> next = list;
    for(Node *p = list; p -> next != nullptr; )
    {
        if(isOddNumberOfFives(p->next->val))
        {
            Node *tmp = p -> next;
            p -> next = tmp -> next;
            tmp -> next = list;
            list = tmp;
            last -> next = tmp;
        }
        else
            p = p -> next;
    }
    cout<<"print list after migrate start" << endl;
    print_list(last);
    cout<<"print list after migrate end" << endl;
    delete last;

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

