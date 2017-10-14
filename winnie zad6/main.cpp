#include <iostream>

/*Dane s¹ ci¹gi a(n), b(n) i c(n) okreœlone nastêpuj¹co:
a(n) = 1 dla n=1, 2
a(n) = a(n-1)+a(n-2) dla n>2
b(n) = 1 dla n=1, 2, 3
b(n) = b(n-1)+b(n-2)+b(n-3) dla n>3
Wyrazy ci¹gu c(n) s¹ kolejnymi liczbami naturalnymi nale¿¹cymi do ci¹gu a(n) lub b(n). Ci¹gi
te przyjmuj¹ wartoœci:
ci¹g a(n) 1 1 2 3 5 8 13 21 ...
ci¹g b(n) 1 1 1 3 5 9 17 31 ...
ci¹g c(n) 1 2 3 5 8 9 13 17 ...
Proszê napisaæ program który wczytuje wprowadzon¹ z klawiatury liczbê naturaln¹ i wypisuje
kolejne wyrazy ci¹gu c(n) mniejsze od wprowadzonej liczby.
using namespace std; */

int main()
{
    int aprev = 1, a = 1;
    int bprevprev = 1, bprev = 1, b = 1;
    int N;
    cin>>N;
    int c = -1;
    for(int i=0; i<N; i++)
    {
        c = min(a,b);
        if(a == c)
        {
            int next = a + aprev;
            aprev = a;
            a = next;
        }
        if(b == c)
        {
            int next = b + bprev + bprevprev;
            bprevprev = bprev;
            bprev = b;
            b = next;
        }
        if(c>=N)
            break;
        cout<<c<<endl;


    }
    return 0;
}
