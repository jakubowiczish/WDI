#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n = 1.0, i = 1;
    while(n <= 2.718)
    {
        n = pow((1 + 1/i),i);
        i++;
        cout<<i-1<<" z kolei liczba e: "<<n<<endl;
    }
    return 0;
}
