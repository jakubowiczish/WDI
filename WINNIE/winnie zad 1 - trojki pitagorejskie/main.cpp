#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    for(int a=1; a<=N-2; a++)
    {
        for(int b=a+1; b<=N-1; b++)
        {
            for(int c=b+1; c<=N; c++)
            {
                if(a*a + b*b == c*c)
                    cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }
    return 0;
}
