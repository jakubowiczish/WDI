#include <iostream>

int main() {
    unsigned long long k;
    std::cin >> k;

    unsigned long long f = 1, fprev = 1, fprevprev = 0;
    bool flag = false;
    while(f <= k) {
        if(k == f * fprev){
            flag = true;
        }

        unsigned long long next = f + fprev;
        fprevprev = fprev;
        fprev = f;
        f = next;
    }
    if(flag)
        std::cout << "Tak, liczba jest iloczynem 2 kolejnych liczb Fibonacciego" << std::endl;
    else
        std::cout << "Nie, ta liczba nie jest iloczynem 2 kolejnych liczb Fibonacciego" << std::endl;
    return 0;
}