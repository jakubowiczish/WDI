#include <iostream>

using namespace std;

int main()
{
    long long n, ostatniacyfra;
    cin>>n;
    long long next = n;
    long long rever = 0;
    while(next)
    {
        ostatniacyfra = next % 10;
        next /= 10;
        rever = rever * 10 + ostatniacyfra;
    }
    if(rever == n)
    {
        cout<<"Jest palindromem"<<endl;
        cout<<n<<" == "<<rever<<endl;
    }
    else
    {
        cout<<"Nie jest palindromem"<<endl;
        cout<<n<<" != "<<rever<<endl;
    }
    return 0;
}
