#include <iostream>
 using namespace std;
int silnia(int n){
    int toReturn = 1;
    for(int i = 2; i <= n; i++){
        toReturn*=i;
    }
    return toReturn;
}
double pow(double x, int p){
    for(int i = 1; i < p; i++){
        x *=x;
    }
    return x;
}
double part(double x, int y){
    return pow(x,y) / (double) silnia(y);
}
double cos(double x){
    double wynik = 1;
    cout << " w " << wynik << endl;
    wynik -= part(x,2);
        cout << " w " << wynik << endl;

    wynik += part(x,4);
    cout << " w " << wynik << endl;

    wynik -= part(x,6);
    cout << " w " << wynik << endl;
    return wynik;
}

int main(int argc, char** argv) {
    double h = 3.14*0.3333;
    cout << h << " " << cos(h) << endl;
    return 0;
}
