#include <iostream>
/*
Dane sπ dwie listy cykliczne powsta≥e przez zapÍtlenie listy jednokierunkowej posortowanej
rosnπco, dla kaødej listy dany jest wskaünik wskazujπcy przypadkowy element w takiej liúcie.
ProszÍ napisaÊ funkcjÍ, ktÛra dla dwÛch list cyklicznych, usuwa z obu list elementy
wystÍpujπce w obu listach. Do funkcji naleøy przekazaÊ wskaüniki na dwie listy, funkcja
powinna zwrÛciÊ ≥πcznπ liczbÍ usuniÍtych elementÛw.
Uwagi:
- czas na rozwiπzanie obu zadaÒ wynosi 45 minut
- za kaøde zadanie moøna otrzymaÊ maksymalnie 5 pkt
- oceniane bÍdπ: czytelnoúÊ, poprawnoúÊ i efektywnoúÊ rozwiπzaÒ
*/
using namespace std;
struct Node{
    int value;
    Node* next;
};
struct List{
    Node* first;
};
Node* addToList(List& list, int value){
    if(list.first == NULL){
        list.first = new Node;
        list.first->value=value;
        list.first->next=NULL;
        return list.first;
    }
    Node* tmp;
    tmp = list.first;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next = new Node;
    tmp->next->value=value;
    tmp->next->next=NULL;
    return tmp->next;

}
void showCycle(List& list){
    Node* tmp;
    tmp = list.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list.first){
            cout << "Element: " << tmp->value << endl;
            tmp=tmp->next;
        }
        cout << "Element: " << tmp->value << endl;
    }
}
void showList(List& list){
    Node* tmp;
    tmp = list.first;
    while(tmp!=NULL){
        cout << "Element: " << tmp->value << endl;
        tmp=tmp->next;
    }
}
void endCycle(List& list){
    Node* tmp;
    tmp = list.first;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=list.first;
}
void removeValueFromCycle(List& list1, int value){
    Node* tmp1 = list1.first;
    while(tmp1->next!=list1.first){ //porÛwnywanie adresÛw pamiÍci, nw czy przejdzie
        if(tmp1->next->value == value){
            Node* nodeToDelete = tmp1->next;
            tmp1->next = tmp1->next->next;
            delete nodeToDelete;
        }
        else {
            tmp1 = tmp1->next;
        }
    }
    //w tym miejscu kolejny node do ten, ktÛry by≥ "pierwszy" w liúcie
    if(tmp1->next->value == value){
        if(tmp1->next == tmp1->next->next){
            delete tmp1->next;
            list1.first=NULL;
        }
        else {
            Node* nodeToDelete = tmp1->next;
            tmp1->next = tmp1->next->next;
            delete nodeToDelete;
            list1.first = tmp1->next;
        }
    }
}
bool checkIfValueExistsInCycle(List& list, int value){
    Node* tmp;
    tmp = list.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list.first){
            if(tmp->value == value) return true;
            tmp=tmp->next;
        }
        if(tmp->value == value) return true;
    }
    return false;
}
void removeDuplicatesFromCycles(List& list1, List& list2){
    Node* tmp;
    tmp = list1.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list1.first){
            if(checkIfValueExistsInCycle(list2,tmp->value)){
                removeValueFromCycle(list2,tmp->value);
                removeValueFromCycle(list1,tmp->value);
                removeDuplicatesFromCycles(list1,list2);
                return;
            }
            tmp=tmp->next;
        }
        if(checkIfValueExistsInCycle(list2,tmp->value)){
            removeValueFromCycle(list2,tmp->value);
            removeValueFromCycle(list1,tmp->value);
            removeDuplicatesFromCycles(list1,list2);
            return;
        }
    }




}
int main(int argc, char** argv) {
    List list1;
    list1.first=NULL;
    addToList(list1,1);
    addToList(list1,1);
    addToList(list1,1);
    Node* node = addToList(list1,2); //pobieram tego noda zeby go daÊ jako wskaünik do listy (w zadaniu jest øe mamy wskaünik na losowy element a nie pierwszy
    addToList(list1,3);
    endCycle(list1);
    list1.first = node;

    List list2;
    list2.first=NULL;
    addToList(list2,1);
    addToList(list2,4);
    addToList(list2,6);
    endCycle(list2);

    cout << "CYKLE PRZED USUWANIEM" << endl;
    cout << "CYKL 1" << endl;
    showCycle(list1);
    cout << "CYKL 2" << endl;
    showCycle(list2);

    removeDuplicatesFromCycles(list1,list2);
    cout << "CYKLE PO USUNIECIU" << endl;
    cout << "CYKL 1" << endl;
    showCycle(list1);
    cout << "CYKL 2" << endl;
    showCycle(list2);

    return 0;
}
