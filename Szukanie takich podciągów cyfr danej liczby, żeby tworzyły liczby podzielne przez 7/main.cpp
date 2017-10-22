#include <iostream>
#include <cmath>
//Szukanie takich podci¹gów cyfr danej liczby, ¿eby tworzy³y liczby podzielne przez 7

using namespace std;

int main()
{
    int n, n2, lc7;
    int lc = 0, g = 1;
    cin >> n;
    n2 = n; // przypisanie aby obliczyc ilosc cyfr liczby n
    while(n2 > 0)
    {
        n2 = n2/10;
        lc++;
        g = g*2; // SPYTAC
    }

    int i2, r;

    lc7 = 0;

    for(int i=0; i<g; i++)
    {
        i2 = i;
        n2 = n;
        r = 0;
        int multip = 1;
        while(i2 > 0) // odt¹d œci¹gniete z gitlaba wieta
        {
            if(i2 % 2 == 1)
            {
                r += (n2 % 10) * multip;
                multip *= 10;
            }
            cout<<r<<endl;
            n2 = n2/10;
            i2 = i2/2;

        }


        if(r % 7 == 0)
        {
            //cout<<"liczba: "<<r<<endl;
            lc7++;
        }
    }
    cout<<lc7<<" liczb";
    return 0;
}

