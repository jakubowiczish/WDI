#include <iostream>

using namespace std;

const int N = 9;
bool t[N][N] =
{
    { false,false,true,true,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
    { false,false,true,false,false,true,true,false,true},
};

int skoki_w[] = {2,1,-1,-2};
int skoki_k[] = {1,2,2,1};

const int inf = N;      //zeby dojsc do N-1 wystarczy N-1 skokow,
                        //wiec inf = N jest wystarczajaca nieskonczonoscia

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int rek(int w, int k) {     //ile minimalnie krokow, bedac w danym polu
    if(w < 0 || w >= N || k < 0 || k >= N || t[w][k] == true) return inf;
    if(w == N-1) return 0;

    int my_min = inf;
    for(int i = 0; i < 4; ++i) {
        my_min = min(my_min, rek(skoki_w[i] + w, skoki_k[i] + k)+1);
    }
    return my_min;
}

int rek_init() {
    int my_min = inf;
    for(int i = 0; i < N; ++i) {
        my_min = min(my_min, rek(0, i));
    }
    return my_min;
}

int main() {
    int wyn = rek_init();
    if(wyn == inf) {
        cout << "nie da sie dojsc" << endl;
    } else {
        cout << wyn << endl;
    }


    return 0;
}
