#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin>>N;

    const int MAX = N*log10(N/M_E) + 10;// liczba cyfr potrzebna na liczbe, dodane + 10 na wszelki wypadek
    int s[MAX];                         // zeby wszystkie cyfry sie zmiescily

    s[0] = 1;
    for(int i=1; i<MAX; i++)
    {
        s[i] = 0;
    }

    int p = 0; // przejscie do kolejnej komorki (nadwyzka, robimy zeby pozostala 1 cyfra w jednej komorce)

    for(int i=1; i<=N; i++) // GLOWNA PETLA
    {
        for(int j=0; j<MAX; j++)
        {
            int tmp = s[j] * i + p;
            p = tmp / 10;
            s[j] = tmp % 10;
            // cout<<s[j]<<endl;
        }

        bool flag = false;

    cout<<"Silnia z: "<<i<<" to: ";

        for(int k = MAX - 1; k>=0; k--)
        {
            if(s[k] > 0)
            {
                flag = true;
            }
            if(flag)
            {
                cout<<s[k];
            }
        }

    cout<<endl;
    }



    return 0;
}
