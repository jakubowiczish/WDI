#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for(int i=1000; i<10000; i++)
    {
        if(i%7 == 0)
        {
            cout<<i<<endl;
            counter++;
        }
    }
    cout<<"Tych liczb jest: "<<counter;
    return 0;
}
