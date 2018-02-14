#include <iostream>

using namespace std;
int main(int argc, char** argv) {
    int T[5];
    for(int i = 0; i < 5; i++){
        T[i] = 0;
    }
    int wKtoreMiejsceTablicyTerazWpisac = 0;
    int liczbaWpisanych = 0;
    int licz = 0;

    while(true){
        if(liczbaWpisanych >=5)
        for(int j = 0; j < 4; j++){
            T[j] = T[j+1];
        }
        int input = 0;
        cin >> input;

        liczbaWpisanych++;

        if(input==0){
            {
                int sum = T[0]+T[1]+T[2]+T[3];
                if(sum/4 == T[4]){
                    cout << "Ta Liczba do wypisania.[4]: " << T[4] << endl;
                }
            }
            {
                int sum = T[0]+T[1]+T[2]+T[4];
                if(sum/4 == T[3]){
                    cout << "Ta Liczba do wypisania.[3]: " << T[3] << endl;
                }
            }
            {
                int sum = T[0]+T[1]+T[3]+T[4];
                if(sum/4 == T[2]){
                    cout << "Ta Liczba do wypisania.[2]: " << T[2] << endl;
                }
            }
            break;
        }

        T[wKtoreMiejsceTablicyTerazWpisac] = input;
        if(liczbaWpisanych==5){
            int sum = T[1]+T[2]+T[3]+T[4];
            if(sum/4 == T[0]){
                cout << "Ta Liczba do wypisania.[0]: " << T[0] << endl;
            }
        }
        if(liczbaWpisanych==5){
            int sum = T[0]+T[2]+T[3]+T[4];
            if(sum/4 == T[1]){
                cout << "Ta Liczba do wypisania.[1]: " << T[1] << endl;
            }
        }
        if(liczbaWpisanych>=5){
            int sum = T[0]+T[1]+T[3]+T[4];
            if(sum/4 == T[2]){
                cout << "Ta Liczba do wypisania.[2]: " << T[2] << endl;
            }
        }

        if(wKtoreMiejsceTablicyTerazWpisac<4) wKtoreMiejsceTablicyTerazWpisac++;
    }
    return 0;
}
