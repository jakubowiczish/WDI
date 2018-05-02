#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i,j;
    string n;
    cin>>n;
    for(i = 0, j = n.length()-1; i<j; i++,j--)
    {
        if(n[i] != n[j])
            break;
    }
    if(i<j)
    {
        cout<<"Nie jest palindromem"<<endl;
    }
    else
        cout<<"Jest palindromem"<<endl;
    return 0;
}
