#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i=1000; i < 10000; i++)
    {
        int k = i;
        k /= 1000;
        if(i == 1000)
            cout << k << endl;
        if(k == 3 or k == 6 or i%3 == 0)
        {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
