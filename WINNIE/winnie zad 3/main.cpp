#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    cin>>k;
    int a = 1, b = 1;
    int temp;
    bool flag = false;
    bool out = false;

    for(int i=2; !out and !flag; i++)
    {
        if(i>k) out = true;
        if(a + b == k) flag = true;
        if(a + b + (a+b) == k) flag = true;
        if(a + b + (a+b) + (a+2*b)) flag = true;
        temp = a;
        a = b;
        b = a + temp;
    }
    if(flag == true)
        cout<<"tak"<<endl;
    else
        cout<<"nie"<<endl;
    return 0;
}
