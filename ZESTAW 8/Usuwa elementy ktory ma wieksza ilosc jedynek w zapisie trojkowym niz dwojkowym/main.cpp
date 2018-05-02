#include <iostream>
/*
Proszê napisaæ funkcjê, która otrzymuj¹c jako parametr wskazuj¹cy na pocz¹tek listy jednokierunkowej,
usuwa z niej wszystkie elementy, w których wartoœæ klucza w zapisie trójkowym ma wiêksz¹ iloœæ jedynek ni¿ dwójek.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void add(Node*& first, int value);
void removeSpecial(Node *first);
void removeValue(Node *&first, int value);
int onesIn3(int n);
int onesIn2(int n);
void print_list(Node *first);

int main()
{
    Node *first = nullptr;
    for(int i=50; i >= 0; i--){
        add(first,i);
        //cout << i << "jedynki w trojkowym: " << onesIn3(i) << endl;
        //cout << i << "jedynki w dwojkowym : " << onesIn2(i) << endl;

    }
    print_list(first);
    removeSpecial(first);
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

void removeSpecial(Node *first)
{
    for(Node *p=first; p -> next != nullptr; p = p -> next)
    {
        for(Node *q=p; q -> next != nullptr; )
        {
            if(onesIn3(p -> val) > onesIn2(q -> next -> val ))
            {
                Node *tmp = q -> next;
                q -> next = tmp -> next;
                delete tmp;
            }
            else
                q = q -> next;
        }
    }
}

void removeValue(Node *&first, int value)
{
    Node *it = first;
    Node *prev = nullptr;
    while(it != nullptr){
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

int onesIn3(int n)
{
    int counter3 = 0;
    while(n > 0){
        if(n%3 == 1){
            counter3++;
        }
        n /= 3;
    }
    return counter3;
}

int onesIn2(int n)
{
    int counter2 = 0;
    while(n > 0){
        if(n%2 == 1){
            counter2++;
        }
        n /= 2;
    }
    return counter2;
}
