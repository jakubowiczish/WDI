#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i=1; i<=1000; i++)
    {
        if(i%3 != 0 and i%7 != 0 and i%11 != 0)
            counter++;
    }
    cout << counter << endl;
    return 0;
}
