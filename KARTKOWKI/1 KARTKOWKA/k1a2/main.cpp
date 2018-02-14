#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char** argv) {
    int n = 3;

    int t1[n][n];
    int t2[n*n];

    t1[0][0] = 1;
    t1[0][1] = 2;
    t1[0][2] = 3;
    t1[1][0] = 1;
    t1[1][1] = 2;
    t1[1][2] = 3;
    t1[2][0] = 1;
    t1[2][1] = 2;
    t1[2][2] = 3;

    int k=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            t2[k++] = t1[i][j];
        }
    }

    sort(t2,t2 + (n*n));
    for(int i = 0; i < (n*n); i++){
        cout << t2[i] << " ";
    }

    return 0;
}
