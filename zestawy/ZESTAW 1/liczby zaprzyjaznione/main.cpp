#include <iostream>

using namespace std;
int sum_of_dividers(int n)
{
    int sum = 0;
    for(int i=1; i <= (n/2); i++)
    {
        if(n%i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

bool czyfriendy(int a, int b)
{
    return (a == sum_of_dividers(b) && b == sum_of_dividers(a) && a != b);
}

int main()
{
    for(int num = 1; num < 1000000; num++)
    {
        while(czyfriendy(num))
        {
            cout<<num<<endl;
        }
    }
    return 0;
}
