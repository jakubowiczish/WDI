#include <math.h>
#include <iostream>
using namespace std;
int main() {
    int a_prev = 1, a = 1; // wyrazy a(n-1), a(n)
    int b_prev_prev = 1, b_prev = 1, b = 1; // wyrazy b(n-2), b(n-1), b(n)
    int c = -1; // wyraz c(n)
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        c = min(a, b);
        // pominiêcie powtarzaj¹cych siê wyrazow
        if (a == c) {
            int next = a_prev + a;
            a_prev = a;
            a = next;
        }
        if (b == c) {
            int next = b_prev_prev + b_prev + b;
            b_prev_prev = b_prev;
            b_prev = b;
            b = next;
        }
        cout << "c(" << (i + 1) << ") = " << c << endl;
    }
    return 0;
}
