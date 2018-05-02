#include <iostream>

using namespace std;

int main()
{
    unsigned long long k;
    cin>>k;

    unsigned long long f = 2, fprev = 1, fprevprev = 1, fprevprevprev = 0;

    // sumy co najwyzej 4 liczb fibonacciego
    unsigned long long sum, sum3, sum3, sum4;

    bool odp = false;

    while (f <= k)
    {
        // aktualizacja sum

        sum = f + fprev + fprevprev + fprevprevprev;
        sum2 = f + fprev + fprevprev;
        sum3 = f + fprev;
        sum4 = f;

        // cout<<"sumy po kolei: "<<sum<<" "<<sum2<<" "<<sum3<<" "<<sum4<<endl;

        if((k == sum) || (k == sum2) || (k == sum3) || (k == sum4))
        {
            cout<<"TAK"<<endl;
            odp = true;
            break;
        }

        unsigned long long next = f + fprev; // wyliczanie kolejnego wyrazu

        //aktualizacja wyrazow

        fprevprevprev = fprevprev;
        fprevprev = fprev;
        fprev = f;
        f = next;
    }

    if(odp == false)
        cout<<"NIE"<<endl;

    return 0;
}
