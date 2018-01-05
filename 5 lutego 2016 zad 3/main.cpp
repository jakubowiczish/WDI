#include<iostream>
using namespace std;
struct node{
    int x;
    int y;
    node* next;
};
/** Okresla w ktorej cwiartce ukladu wspolrzednych znajduje sie punkt
 *  @param x,y - wspolrzedne punktu
 *  @return 0 jezeli lezy na osi X lub Y, 1-4 odpowiednio dla cwiartek
 */
int getQuadrant(int x, int y){
    if(x==0 || y==0)
        return 0;
    if(x>0 && y>0)
        return 1;
    if(x<0 && y>0)
        return 2;
    if(x<0 && y<0)
        return 3;
    if(x>0 && y<0)
        return 4;
}
/** Dzieli zbior punktow dany w postaci lancucha na podzbiory w zaleznosci do ktorej cwiartki nalezy punkt
 *  @param in - lancuch do podzielenia
 *  @param @return out1 - lancuch zawierajacy punkty z I cwiartki
 *  @param @return out2 - lancuch zawierajacy punkty z II cwiartki
 *  @param @return out3 - lancuch zawierajacy punkty z III cwiartki
 *  @param @return out4 - lancuch zawierajacy punkty z IV cwiartki
 */
void splitByQuadrant(node* in, node *&out1, node *&out2, node *&out3, node *&out4){
    out1 = NULL;
    out2 = NULL;
    out3 = NULL;
    out4 = NULL;
    while(in != NULL){
        node* next = in->next;
        switch(getQuadrant(in->x, in->y)){
            // punkt lezy na osi wspolrzednych -> usuwamy
            case 0:
                delete in;
                break;
                // punkt lezy w I cwiartce -> przepinamy do out1
            case 1:
                in->next = out1;
                out1 = in;
                break;
                // punkt lezy w II cwiartce -> przepinamy do out2
            case 2:
                in->next = out2;
                out2 = in;
                break;
                // punkt lezy w III cwiartce -> przepinamy do out3
            case 3:
                in->next = out3;
                out3 = in;
                break;
                // punkt lezy w IV cwiartce -> przepinamy do out4
            case 4:
                in->next = out4;
                out4 = in;
                break;
        }
        in = next;
    }
}
/** Tworzy nowy lancuch z zadanymi wartosciami
 *  @param values[length][2] - wartosci do umieszczenia w lancuchu
 *  @param length - dlugosc lancucha
 *  @return wskaznik na pierwszy element nowo utworzonego lancucha
 */
node* createChain(int values[][2], int length){
    node* first = new node;
    first->x = values[0][0];
    first->y = values[0][1];
    node* A = first;
    for(int i = 1; i<length; i++){
        A->next = new node;
        A = A->next;
        A->x = values[i][0];
        A->y = values[i][1];
    }
    return first;
}
/** Wypisuje dany lancuch na standardowe wyjscie
 *  @param in - wskaznik na pierwszy element lancucha do wypisania
 */
void printChain(node* in){
    while(in != NULL){
        cout << " -> (" << in->x << "," << in->y << ")";
        in = in->next;
    }
    cout << endl;
}
/** Usuwa dany lancuch z pamieci
 *  @param in - wskaznik na pierwszy element lancucha do usuniecia
 */
void deleteChain(node* in){
    while(in != NULL){
        node* temp = in;
        in = in->next;
        delete temp;
    }
}
int main(){
    // tworzenie przykladowego ciagu
    int values[9][2] = {
            { 1, 3},
            {-2,-3},
            { 7,-5},
            {-8, 1},
            { 0, 2},
            {-7,-2},
            { 1, 6},
            {-9, 0},
            {-4,-3}
    };
    node* in = createChain(values, 9);
    // wypisanie danych wejsciowych
    cout << "Input:" << endl;
    printChain(in);
    // dzielenie
    node* out1 = NULL;
    node* out2 = NULL;
    node* out3 = NULL;
    node* out4 = NULL;
    splitByQuadrant(in, out1, out2, out3, out4);
    // wypisanie wyniku
    cout << endl << "Output:" << endl;
    printChain(out1);
    printChain(out2);
    printChain(out3);
    printChain(out4);
    // usuwanie lancuchow
    deleteChain(out1);
    deleteChain(out2);
    deleteChain(out3);
    deleteChain(out4);
    return 0;
}
