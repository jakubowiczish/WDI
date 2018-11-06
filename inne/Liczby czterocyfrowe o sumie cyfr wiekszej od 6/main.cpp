#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i=1000; i<10000; i++)
    {
        int digits = 0;
        int k = i;
        while(k > 0)
        {
            digits += k%10;
            k /= 10;
        }
        if(digits > 6)
            counter++;
    }
    cout << counter << endl;
    return 0;
}
