#include <iostream>

using namespace std;

int main()
{
int n;
bool flag=0;
cin>> n;
int fib[n];
fib[0]=0;
fib[1]=1;


// zapelnienie tablicy
for (int i=2; i<n; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

// sprawdzanie iloczynow kolejnych elementow dla danego;
// przechodzenie do nastepnego elementu

for (int i=0; i<n && !flag; i++)
    {
    for (int j=i+1; j<n; j++)
        {
        if (fib[i]*fib[j]==n) flag=1;
        }
    }



//wypisywanie
if (flag) cout <<"TAK";
    else cout <<"NIE";
}
