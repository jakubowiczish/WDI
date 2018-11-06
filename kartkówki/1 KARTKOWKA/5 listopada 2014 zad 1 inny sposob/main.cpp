#include <iostream>
using namespace std;
int main() {

    int n= 0;
    int* tablica;

    while(true){
        int temp = 0;
        cin >> temp;

        if(temp==0) break;
        int tablica2[n];
        n++;

        for(int i = 0; i < (n-1); i++){
            tablica2[i] = tablica[i];
        }

        tablica2[n-1] = temp;
        tablica = tablica2;
    }
    cout << "Wypisujê tablicê:" << endl;

    for(int i = 0; i < n; i++){
        cout << tablica[i] << endl;
    }

    return 1;
}
