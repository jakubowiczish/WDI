#include <iostream>

using namespace std;

int main()
{
    int num = 1; // liczba doskonala do wyszukania, zaczynamy od 1
    int sum_of_dividers = 0;
    while(num < 1000000)
    {

        for(int i=1; i<= (num/2); i++)
        {
            if(num%i == 0)
            {
                sum_of_dividers += i;
            }
        }

        if(sum_of_dividers == num)
        {
            cout<<num<<endl;
        }

        sum_of_dividers = 0;
        num++;

    }
    return 0;
}
