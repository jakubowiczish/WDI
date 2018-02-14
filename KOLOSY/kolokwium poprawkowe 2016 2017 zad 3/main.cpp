#include <iostream>
/*
 Dane s¹ trzy listy jednokierunkowe uporz¹dkowane rosn¹co bez powtarzaj¹cych siê
liczb. Proszê napisaæ funkcjê która usunie w ka¿dej liœcie elementy powtarzaj¹ce siê
w trzech listach. Funkcja ma zwróciæ liczbê usuniêtych elementów.
*/
struct Node {
    int value;
    Node* next;
};

void add(Node*& first, int value) {
    if (first == nullptr) {
        first = new Node;
        first->value = value;
        first->next = nullptr;
    } else {
        Node* new_first = new Node;
        new_first->value = value;
        new_first->next = first;
        first = new_first;
    }
}

void remove(Node*& first, int value) {
    Node* it = first;
    Node* prev = nullptr;
    while (it != nullptr) {
        if (it->value == value) {
            if (prev == nullptr) {
                first = first->next;
            } else {
                prev->next = it->next;
                delete it;
            }
        }
        prev = it;
        it = it->next;
    }
}

void print(Node* first) {
    while (first != nullptr) {
        std::cout << first->value << " ";
        first = first->next;
    }
    std::cout << std::endl;
}

int remove_duplicates(Node*& first1, Node*& first2, Node*& first3) {
    Node* it1;
    Node* it2;
    Node* it3;

    int deleted = 0;

    it1 = first1;
    while (it1 != nullptr) {
        it2 = first2;
        while (it2 != nullptr) {
            it3 = first3;
            while (it3 != nullptr) {
                if ((it1->value == it2->value) && (it2->value == it3->value)) {
                    remove(first1, it1->value);
                    remove(first2, it2->value);
                    remove(first3, it3->value);

                    deleted += 3;
                }
                it3 = it3->next;
            }
            it2 = it2->next;
        }
        it1 = it1->next;
    }

    return deleted;
}

int main() {
    Node* f1 = nullptr;
    Node* f2 = nullptr;
    Node* f3 = nullptr;

    for (int i = 5; i > 0; i--) add(f1, i);
    for (int i = 4; i > 0; i--) add(f2, i);
    for (int i = 3; i > 0; i--) add(f3, i);

    print(f1);
    print(f2);
    print(f3);

    std::cout << "Usunieto: " << remove_duplicates(f1, f2, f3) << std::endl;

    print(f1);
    print(f2);
    print(f3);

    return 0;
}
