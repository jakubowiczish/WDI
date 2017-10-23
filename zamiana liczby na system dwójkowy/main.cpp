#include <iostream>

using namespace std;

int main()
{
    int number;
    cin>>number;
    while(number > 0)
    {
        cout<<number%2;
        number /= 2;
    }
    return 0;
}
